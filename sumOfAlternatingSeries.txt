//series won't work after first two digits and too frustrated too solve it

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
float altSum(int);
int main()
{
int ans;
while (1)
{
printf("Enter a number: ");
scanf("%d", &ans);
if (ans <= 0)
continue; // change to break and see the impact
printf("Sum of the first %d alternate terms is %f \n", ans,
altSum(ans));
}
}
// Returns the sum of alternating series: 1 - 1/2 + 1/3 - 1/4 + …. (+/-) 1/n
float altSum(int n)
{
    double i = 0;
    double number = 0;
    double sum = 0;
    double k = 0;
    double sum2 = 0;
   for ( i = 1; i <= n ; i++){
    sum += 1 / (sum + 1);
    sum2 = fabs(sum);
   }
   if( n % 2 == 0)
    for ( k = 1; k <= n ; k++){
    sum +=  -(1 / (n)) + -1;
    sum2 = fabs(sum);
   }
   
    return sum2;
}
