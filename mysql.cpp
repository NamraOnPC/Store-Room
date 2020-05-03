#define _CRT_SECURE_NO_WARNINGS

#include <mysql.h>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define HOST "********************"
#define USER "*****************"
#define PASS "*****************"
#define DB "*************"
#define PORT ****

template<typename T> void printElement(T t, const int& width)
{
	cout << left << setw(width) << setfill(' ') << t;
}
void Clear();
ostream& line(const int len, const char ch);
int menu();
int getIntInRange(int min, int max);
int getInt();
bool yes();

int findEmployee(MYSQL* conn, int employeeNumber, struct Employee* emp);
void displayEmployee(MYSQL* conn, struct Employee* emp);
void displayAllEmployees(MYSQL* conn);
void insertEmployee(MYSQL* conn, struct Employee* emp);
void updateEmployee(MYSQL* conn, const int no);
void deleteEmployee(MYSQL* conn, const int no);

struct Employee {
	int employeeNumber;
	char lastName[50];
	char firstName[50];
	char email[100];
	char phone[50];
	char extension[10];
	char reportsTo[100];
	char jobTitle[50];
	char city[50];

};

int main() {
	bool exit = false;
	int option;
	Employee* emp = nullptr;

	MYSQL* conn = mysql_init(0);

	conn = mysql_real_connect(conn, HOST, USER, PASS, DB, PORT, nullptr, 0);

	if (conn) {
		cout << "Successful connection to Database" << endl << endl;
		int ok = mysql_set_server_option(conn, MYSQL_OPTION_MULTI_STATEMENTS_ON);
		mysql_autocommit(conn, false);

		do {
			option = menu();

			switch (option) {
			case 1:
				emp = new Employee();

				system("CLS");
				displayEmployee(conn, emp); cout << endl;
				delete emp;

				system("PAUSE");
				system("CLS");
				break;
			case 2:
				system("CLS");
				displayAllEmployees(conn);
				cout << endl;

				system("PAUSE");
				system("CLS");
				break;
			case 3:
				emp = new Employee();

				system("CLS");
				insertEmployee(conn, emp);
				cout << endl;
				delete emp;

				system("PAUSE");
				system("CLS");
				break;
			case 4:
				system("CLS");
				int no;
				cout << "Enter Employee Number: ";
				no = getInt();
				updateEmployee(conn, no);
				cout << endl;

				system("PAUSE");
				system("CLS");
				break;
			case 5:
				system("CLS");
				cout << "Enter Employee Number: ";
				no = getInt();
				deleteEmployee(conn, no);
				cout << endl;

				system("PAUSE");
				system("CLS");
				break;
			case 0:
				cout << "Exit the program? (Y)es/(N)o: ";
				exit = yes();
				cout << endl;
				system("CLS");
				break;
			}
		} while (!exit);

		mysql_rollback(conn);
		mysql_close(conn);
	}
	else {
		cout << "Connection Failed. Error: " << mysql_error(conn) << endl;
	}
}

void Clear() {
	while (getchar() != '\n') {
		;
	}
}

ostream& line(const int len, const char* ch) {
	for (int i = 0; i < len; i++, cout << ch);
	return cout;
}

int menu() {
	line(21, ""); cout << " HR Menu "; line(21, ""); cout << endl;
	cout << "1) Find Employee" << endl;
	cout << "2) Employees Report" << endl;
	cout << "3) Add Employee" << endl;
	cout << "4) Update Employee" << endl;
	cout << "5) Remove Employee" << endl;
	cout << "0) Exit" << endl << endl;

	cout << "Select an option:> ";

	return getIntInRange(0, 5);
}

int getIntInRange(int min, int max) {
	bool done = false;
	int value;

	do {
		value = getInt();
		if (value > max || value < min) {
			cout << "* OUT OF RANGE * <Enter a number between " << min << " and " << max << ">: ";
		}
		else {
			done = true;
		}

	} while (!done);

	return value;
}

int getInt() {

	bool done = false;
	int first, value;
	char after;

	do {
		first = scanf("%d%c", &value, &after);
		if (first == 0) {
			cout << "* INVALID INTEGER * <Please enter an integer>: ";
			Clear();
		}
		else if (after != '\n') {
			cout << "* INVALID INTEGER * <Please enter an integer>: ";
			Clear();
		}
		else if (first < INT_MIN || first > INT_MAX) {
			cout << "* INVALID INTEGER * <Please enter an integer>: ";
			Clear();
		}
		else {
			done = true;
		}

	} while (!done);

	return value;

}

bool yes() {

	char answer, after;
	bool value = false;

	do {
		scanf(" %c%c", &answer, &after);

		if (after != '\n')
			answer = '1';

		switch (answer) {

		case 'n':
		case 'N':
			value = false;
			break;

		case 'y':
		case 'Y':
			value = true;
			break;

		default:
			printf("* INVALID ENTRY * <Only (Y)es or (N)o are acceptable>: ");
			Clear();
			break;
		}
	} while (answer != 'n' && answer != 'y' && answer != 'N' && answer != 'Y');

	answer = ' ';

	return value;

}

int findEmployee(MYSQL* conn, int employeeNumber, struct Employee* emp) {
	int exit_code = 0;
	string query = "SELECT emp.employeeNumber, emp.lastName, emp.firstName, emp.email, of.phone, emp.extension, emp.reportsTo, emp.jobTitle, of.city "
		"FROM employees emp JOIN offices of ON emp.officeCode = of.officeCode "
		"WHERE emp.employeeNumber = " + std::to_string(employeeNumber);

	if (!mysql_query(conn, query.c_str())) {
		MYSQL_RES* result = mysql_store_result(conn);

		if (result) {
			MYSQL_ROW row = mysql_fetch_row(result);
			if (row != nullptr) {
				if (emp != nullptr) {
					emp->employeeNumber = std::atoi(row[0]);
					strcpy(emp->lastName, row[1]);
					strcpy(emp->firstName, row[2]);
					strcpy(emp->email, row[3]);
					strcpy(emp->phone, row[4]);
					strcpy(emp->extension, row[5]);
					if (row[6] != nullptr) {
						strcpy(emp->reportsTo, row[6]);
					}
					strcpy(emp->jobTitle, row[7]);
					strcpy(emp->city, row[8]);
				}
				exit_code = 1;
			}
			else {
				cout << "invalid data" << endl;
			}
		}
		else {
			cout << "Error message: " << mysql_error(conn) << ": " << mysql_errno(conn) << endl;
		}
	}
	else {
		cout << "Error message: " << mysql_error(conn) << ": " << mysql_errno(conn) << endl;
	}

	return exit_code;
}

void displayEmployee(MYSQL* conn, Employee* emp) {
	int number;
	cout << "Enter Employee Number: ";
	number = getInt();
	if (findEmployee(conn, number, emp)) {
		cout << endl;
		cout << "employeeNumber = " << emp->employeeNumber << endl;
		cout << "lastName = " << emp->lastName << endl;
		cout << "firstName = " << emp->firstName << endl;
		cout << "email = " << emp->email << endl;
		cout << "phone = " << emp->phone << endl;
		cout << "extension = " << emp->extension << endl;
		cout << "reportsTo = " << emp->reportsTo << endl;
		cout << "jobTitle = " << emp->jobTitle << endl;
		cout << "city = " << emp->city << endl;
	}
	else {
		cout << "Employee " << number << " does not exist." << endl;}
}

void displayAllEmployees(MYSQL* conn) {
	string query = "SELECT 	emp.employeeNumber, emp.firstName, emp.lastName, emp.email, of.phone, emp.extension, mng.firstName, mng.lastName "
		"FROM(employees emp LEFT JOIN employees mng ON emp.reportsTo = mng.employeeNumber "
		"JOIN offices of ON emp.officeCode = of.officeCode);";

	if (!mysql_query(conn, query.c_str())) {
		MYSQL_RES* result = mysql_store_result(conn);
		if (result) {
			printElement("E", 6); printElement("Employee Name", 20); printElement("Email", 35);
			printElement("Phone", 20); printElement("Ext", 10); printElement("Manager", 20);
			cout << endl; line(111, "-"); cout << endl;

			while (MYSQL_ROW row = mysql_fetch_row(result)) {
				if (row != nullptr) {
					std::string emp_frst(row[1]);
					std::string emp_lst(row[2]);
					string emp_name = emp_frst + " " + emp_lst;

					string mng_name;
					if (row[6] && row[7]) {
						std::string mng_frst(row[6]);
						std::string mng_lst(row[7]);
						mng_name = mng_frst + " " + mng_lst;
					}
					else {
						mng_name = "";
					}


					printElement(row[0], 6);
					printElement(emp_name, 20);
					printElement(row[3], 35);
					printElement(row[4], 20);
					printElement(row[5], 10);
					printElement(mng_name, 20);
					cout<<endl;}
				else {
					cout << "Invalid data" << endl;}
			}
		}
		else {
			cout << "Error message: " << mysql_error(conn) << ": " << mysql_errno(conn) << endl;}
	}
	else {
		cout << "Error message: " << mysql_error(conn) << ": " << mysql_errno(conn) << endl;}
}

void insertEmployee(MYSQL* conn, Employee* emp) {
	cout << "Employee Number: ";
	emp->employeeNumber = getInt();

	if (!findEmployee(conn, emp->employeeNumber, nullptr)) {
		cout << "Last Name: ";
		cin.get(emp->lastName, 51, '\n');
		Clear();
		cout << "First Name: ";
		cin.get(emp->firstName, 51, '\n');
		Clear();
		cout << "Email: ";
		cin.get(emp->email, 101, '\n');
		Clear();
		cout << "Extension: ";
		cin.get(emp->extension, 11, '\n');
		Clear();
		cout << "Job Title: ";
		cin.get(emp->jobTitle, 51, '\n');
		Clear();
		cout << "City: ";
		cin.get(emp->city, 51, '\n');
		Clear();

		string query = "INSERT INTO employees VALUES ("
			+ std::to_string(emp->employeeNumber) + ",'" + std::string(emp->lastName) + "','"
			+ std::string(emp->firstName) + "','" + std::string(emp->extension) + "','"
			+ std::string(emp->email) + "'," + "1" + "," + "1002" + ",'" + std::string(emp->jobTitle) + "');";

		if (mysql_query(conn, query.c_str())) {
			cout << "Error message: " << mysql_error(conn) << ": " << mysql_errno(conn) << endl;
		}
		else {
			cout << endl << "Employee " << emp->employeeNumber << " was successfully added." << endl;
		}
	}
	else {
		cout << "An employee with the same employee number exists." << endl;
	}

}

void updateEmployee(MYSQL* conn, const int number) {
	if (findEmployee(conn, number, nullptr)) {
		char ext[11];
		cout << "New Extension: ";
		cin.get(ext, 11, '\n');
		Clear();

		string query = "UPDATE employees SET extension = '" + std::string(ext) + "' WHERE employeeNumber = " + std::to_string(number) + ";";
		if (mysql_query(conn, query.c_str())) {
			cout << "Error message: " << mysql_error(conn) << ": " << mysql_errno(conn) << endl;
		}
		else {
			cout << endl << "Employee " << number << " was successfully updated." << endl;
		}
	}
	else {
		cout << "Employee " << number << " does not exist." << endl;
	}
}


void deleteEmployee(MYSQL* conn, const int number) {
	if (findEmployee(conn, number, nullptr)) {
		string query = "DELETE FROM employees WHERE employeeNumber = " + std::to_string(number) + ";";

		if (mysql_query(conn, query.c_str())) {
			cout << "Error message: " << mysql_error(conn) << ": " << mysql_errno(conn) << endl;}
		else {
			cout << "The employee has been deleted." << endl;}
	}
	else {
		cout << "The employee does not exist." << endl;}
}
