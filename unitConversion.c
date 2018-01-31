#include <stdio.h>
#include <conio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

void Length(void);

void Weight(void);

void Time(void);

int main ()
{
	float km,m,cm,mil,to,kg,g,mg,s,min,h,d,c,f,k;
	int menu,menu2,menu3,menu4,menu5,menu6,menu7,menu8,menu9,menu10,menu11,menu12,menu13,menu14,menu15,menu16,menu17,menu18,menu19,menu20;
	do
	{
		puts("Please choose the type of units to convert");
		puts("1) Lenght");
		puts("2) Mass");
		puts("3) Time");
		puts("4) Temperature");
		scanf("%d",&menu);	
		switch(menu)
		{ 		
		case 1:
			   Length();
			   break;
				         case 2:
				                Weight();
				                break;
				
		case 3:
			   Time();
			   break;
		case 4:
			   puts("Choose the units to convert from");
			   puts("1) Celsius");
			   puts("2) Fahrenheit");
			   puts("3) Kelvin");
			   if(menu=4)
		           {
			         int menu17;
			         scanf("%d",&menu17);
			         switch(menu17)
				       {
				         case 1:
				                puts("Choose the units to convert to");
				                puts("1) Fahrenheit");
				                puts("2) Kelvin");
				                if (menu17=1)
			                       {
				                    int menu18;
			                        scanf("%d",&menu18);
			                        switch(menu18)
				                       {
				                        case 1:
				                               puts("Please enter Celsius");
				                               scanf("%f",&c);
				                               f=(c*1.8)+32;
				                               printf("%.2f Celsius are %.2f Fahrenheit\n", c,f);
				                               break;
				                        case 2:
				                               puts("Please enter Celsius");
				                               scanf("%f",&c);
				                               k=c+273.15;
				                               printf("%.2f Celsius are %.2f Kelvins\n", c,k);
				                               break;
				                        }
						           }
								 break;
				         case 2:
				                puts("Choose the units to convert to");
				                puts("1) Celsius");
				                puts("2) Kelvins");
				                if(menu17=2)
			                       {
				                    int menu19;
			                        scanf("%d",&menu19);
			                        switch(menu19)
				                     {
				                      case 1:
				                             puts("Please enter Fahrenheit");
				                             scanf("%f",&f);
				                             c=(f-32)*1.8;
				                             printf("%.2f Fahrenheit are %.2f Celsius\n", f,c);
				                             break;
				                      case 2:
				                             puts("Please enter Fahrenheit");
				                             scanf("%f",&f);
				                             k=(0.55555*f)+255.38;
				                             printf("%.2f Fahrenheit are %.2f Kelvins\n",f,k);
				                             break;
				                      }
					              }
                                break;
				          case 3:
				                puts("Choose the units to convert to");
				                puts("1) Celsius");
				                puts("2) Fahrenheit");
				                if(menu17=3)
			                      {
				                   int menu20;
			                       scanf("%d",&menu20);
			                       switch(menu20)
				                     {
				                      case 1:
				                             puts("Please enter Kelvins");
				                             scanf("%f",&k);
				                             c=k-273.15;
				                             printf("%.2f Kelvins are %.2f Celsius\n", k,c);
				                             break;
				                       case 2:
				                             puts("Please enter Kelvins");
				                             scanf("%f",&k);
				                             f=1.8*(k-273.15)+32;
				                             printf("%.2f Kelvins are %.2f Celsius\n",k,f);
				                             break;
				                       }
					               }
				                break;
				          
					  }
		          }

			   }//*switch(menu)*//		
		
} while(menu!=0);
			getch();
			return 0;
			}
			
			
			
			
			
			
			
void Length(void){
float km,m,cm,mil,to,kg,g,mg,s,min,h,d,c,f,k;
	int menu,menu2,menu3,menu4,menu5,menu6;
puts("Choose the units to convert from");
				puts("1) Kilometer");
				puts("2) Metre");
				puts("3) Centimetre");
				puts("4) Millimetre");
				if(menu=1)
		           {
			         int menu2;
			         scanf("%d",&menu2);
			         switch(menu2)
				       {
				         case 1:
				                puts("Choose the units to convert to");
				                puts("1) Metre");
				                puts("2) Centimetre");
				                puts("3) Millimetres");
				                if (menu2=1)
			                       {
				                    int menu3;
			                        scanf("%d",&menu3);
			                        switch(menu3)
				                       {
				                        case 1:
				                               puts("Please enter Kilometres");
				                               scanf("%f",&km);
				                               m=km*1000;
				                               printf("%.2f Kilometres are %.2f metres\n", km,m);
				                               break;
				                        case 2:
				                               puts("Please enter Kilometres");
				                               scanf("%f",&km);
				                               cm=km*100000;
				                               printf("%.2f Kilometres are %.2Ef Centimetres\n", km,cm);
				                               break;
				                        case 3:
				                               puts("Please enter Kilometres");
				                               scanf("%f",&km);
				                               mil=km*100000;
				                               printf("%.2f Kilometres are %.2Ef Millimetres\n", km,mil);
				                               break;
				                       }
						           }
								 break;
				         case 2:
				                puts("Choose the units to convert to");
				                puts("1) Kilometre");
				                puts("2) Centimetre");
				                puts("3) Millimetres");
								if(menu2=2)
			                       {
				                    int menu4;
			                        scanf("%d",&menu4);
			                        switch(menu4)
				                     {
				                      case 1:
				                             puts("Please enter Metres");
				                             scanf("%f",&m);
				                             km=m/1000;
				                             printf("%.2f Metres are %.2f Kilometres\n", m,km);
				                             break;
				                      case 2:
				                             puts("Please enter Metres");
				                             scanf("%f",&m);
				                             cm=m*100;
				                             printf("%.2f Metres are %.2f Centimetres\n",m,cm);
				                             break;
				                      case 3:
				                             puts("Please enter Metres");
				                             scanf("%f",&m);
				                             mil=m*1000;
				                             printf("%.2f Metres are %.2f Millimetres\n", m,mil);
				                             break;
			                         }
					              }
                                break;
				          case 3:
				                puts("Choose the units to convert to");
				                puts("1) Kilometre");
				                puts("2) Metre");
				                puts("3) Millimetres");
								if(menu2=3)
			                      {
				                   int menu5;
			                       scanf("%d",&menu5);
			                       switch(menu5)
				                     {
				                      case 1:
				                             puts("Please enter Centimetres");
				                             scanf("%f",&cm);
				                             km=cm/100000;
				                             printf("%.2f Centimetres are %.2Ef Kilometres\n", cm,km);
				                             break;
				                       case 2:
				                             puts("Please enter Centimetres");
				                             scanf("%f",&cm);
				                             m=cm/100;
				                             printf("%.2f Centimetres are %.2f Metres\n",cm,m);
				                             break;
				                        case 3:
				                             puts("Please enter Centimetres");
				                             scanf("%f",&cm);
				                             mil=cm*100;
				                             printf("%.2f Metres are %.2f Millimetres\n", cm,mil);
				                             break;
			                         }
					               }
				                break;
				          case 4:
				                puts("Choose the units to convert to");
				                puts("1) Kilometre");
				                puts("2) Metre");
				                puts("3) Centimetre");
							    if(menu2=4)
			                      {
				                   int menu6;
			                       scanf("%d",&menu6);
			                       switch(menu6)
				                      {
				                       case 1:
				                              puts("Please enter Milimetres");
				                              scanf("%f",&mil);
				                              km=mil/1000000;
				                              printf("%.2f Milimetres are %.2Ef Kilometres\n", mil,km);
				                              break;
				                        case 2:
				                               puts("Please enter Milimetres");
				                               scanf("%f",&mil);
				                               m=mil/1000;
				                               printf("%.2f Milimetres are %.2f Metres\n",mil,m);
				                               break;
				                        case 3:
				                               puts("Please enter Milimetres");
				                               scanf("%f",&mil);
				                               cm=mil/10;
				                               printf("%.2f Millimetres are %.2f Centimetres\n", mil,cm);
				                               break;
			                            }
					               }
								break;
					  }
		          } 
};


void Weight(void){
    
    float km,m,cm,mil,to,kg,g,mg,s,min,h,d,c,f,k;
    
    int menu,menu2,menu3,menu4,menu5,menu6,menu7,menu8,menu9,menu10,menu11,menu12,menu13,menu14,menu15,menu16,menu17,menu18,menu19,menu20;
    
    puts("Choose the units to convert to");
				                puts("1) Tonne");
				                puts("2) Gram");
				                puts("3) Milligram");
								if(menu7=2)
			                       {
				                    int menu9;
			                        scanf("%d",&menu9);
			                        switch(menu9)
				                     {
				                      case 1:
				                             puts("Please enter Kilograms");
				                             scanf("%f",&kg);
				                             to=kg/1000;
				                             printf("%.2f Kilograms are %.2f Tonnes\n", kg,to);
				                             break;
				                      case 2:
				                             puts("Please enter Kilograms");
				                             scanf("%f",&kg);
				                             g=kg*1000;
				                             printf("%.2f Kilograms are %.2f Grams\n",kg,g);
				                             break;
				                      case 3:
				                             puts("Please enter Kilograms");
				                             scanf("%f",&kg);
				                             mg=kg*100000;
				                             printf("%.2f Kilograms are %.2Ef Milligrams\n", m,mil);
				                             break;
			                         }
					              }
				                puts("Choose the units to convert to");
				                puts("1) Tonne");
				                puts("2) Kilogram");
				                puts("3) Milligram");
								if(menu7=3)
			                      {
				                   int menu10;
			                       scanf("%d",&menu10);
			                       switch(menu10)
				                     {
				                      case 1:
				                             puts("Please enter Grams");
				                             scanf("%f",&g);
				                             to=g/1000000;
				                             printf("%.2f Grams are %.2Ef Tonnes\n", g,to);
				                             break;
				                       case 2:
				                             puts("Please enter Grams");
				                             scanf("%f",&g);
				                             kg=g/1000;
				                             printf("%.2f Grams are %.2f Kilograms\n",g,kg);
				                             break;
				                        case 3:
				                             puts("Please enter Grams");
				                             scanf("%f",&g);
				                             mg=g*1000;
				                             printf("%.2f Grams are %.2f Milligrams\n", g,mg);
				                             break;
			                         }
					               }
				                puts("Choose the units to convert to");
				                puts("1) Tonne");
				                puts("2) Kilogram");
				                puts("3) Gram");
							    if(menu7=4)
			                      {
				                   int menu11;
			                       scanf("%d",&menu11);
			                       switch(menu11)
				                      {
				                       case 1:
				                              puts("Please enter Milligrams");
				                              scanf("%f",&mg);
				                              to=mg/1000000000;
				                              printf("%.2f Milligrams are %.2Ef Tonnes\n", mg,to);
				                              break;
				                        case 2:
				                               puts("Please enter Milligrams");
				                               scanf("%f",&mg);
				                               kg=mg/1000000;
				                               printf("%.2f Milimetres are %.2Ef Metres\n",mg,kg);
				                               break;
				                        case 3:
				                               puts("Please enter Miligrams");
				                               scanf("%f",&mg);
				                               g=mg/1000;
				                               printf("%.2f Milligrams are %.2f grams\n", mg,g);
				                               break;
			                            default :
			                            (printf("select something"));
}
				                      }
				                      };
				                      
void Time(void){
    
    float km,m,cm,mil,to,kg,g,mg,s,min,h,d,c,f,k;
    
    int menu,menu2,menu3,menu4,menu5,menu6,menu7,menu8,menu9,menu10,menu11,menu12,menu13,menu14,menu15,menu16,menu17,menu18,menu19,menu20;
    puts("Choose the units to convert from");
			   puts("1) Seconds");
			   puts("2) Minutes");
			   puts("3) Hours");
			   puts("4) Days");
		       if(menu=3)
		           {
			         int menu12;
			         scanf("%d",&menu12);
			         switch(menu12)
				       {
				         case 1:
				                puts("Choose the units to convert to");
				                puts("1) Minutes");
				                puts("2) Hours");
				                puts("3) Days");
				                if (menu12=1)
			                       {
				                    int menu13;
			                        scanf("%d",&menu13);
			                        switch(menu13)
				                       {
				                        case 1:
				                               puts("Please enter Seconds");
				                               scanf("%f",&s);
				                               min=s/60;
				                               printf("%.2f Seconds are %.2f Minutes\n", s,min);
				                               break;
				                        case 2:
				                               puts("Please enter Seconds");
				                               scanf("%f",&s);
				                               h=s/3600;
				                               printf("%.2f Seconds are %.2f Hours\n", s,h);
				                               break;
				                        case 3:
				                               puts("Please enter Seconds");
				                               scanf("%f",&s);
				                               d=s/86400;
				                               printf("%.2f Seconds are %.2f Days\n", s,d);
				                               break;
				                       }
						           }
								 break;
				         case 2:
				                puts("Choose the units to convert to");
				                puts("1) Seconds");
				                puts("2) Hours");
				                puts("3) Days");
								if(menu12=2)
			                       {
				                    int menu14;
			                        scanf("%d",&menu14);
			                        switch(menu14)
				                     {
				                      case 1:
				                             puts("Please enter Minutes");
				                             scanf("%f",&min);
				                             s=min*60;
				                             printf("%.2f Minutes are %.2f Seconds\n", min,s);
				                             break;
				                      case 2:
				                             puts("Please enter Minutes");
				                             scanf("%f",&min);
				                             h=min/60;
				                             printf("%.2f Minutes are %.2f Hours\n",min,h);
				                             break;
				                      case 3:
				                             puts("Please enter Minutes");
				                             scanf("%f",&min);
				                             d=min/1440;
				                             printf("%.2f Minutes are %.2Ef Days\n", min,d);
				                             break;
			                         }
					              }
                                break;
				          case 3:
				                puts("Choose the units to convert to");
				                puts("1) Seconds");
				                puts("2) Minutes");
				                puts("3) Days");
								if(menu12=3)
			                      {
				                   int menu15;
			                       scanf("%d",&menu15);
			                       switch(menu15)
				                     {
				                      case 1:
				                             puts("Please enter Hours");
				                             scanf("%f",&h);
				                             s=h*3600;
				                             printf("%.2f Hours are %.2f Seconds\n", h,s);
				                             break;
				                       case 2:
				                             puts("Please enter Hours");
				                             scanf("%f",&h);
				                             min=h*60;
				                             printf("%.2f Hours are %.2f Minutes\n",h,min);
				                             break;
				                        case 3:
				                             puts("Please enter Hours");
				                             scanf("%f",&h);
				                             d=h/24;
				                             printf("%.2f Hours are %.2f Days\n", h,d);
				                             break;
			                         }
					               }
				                break;
				          case 4:
				                puts("Choose the units to convert to");
				                puts("1) Seconds");
				                puts("2) Minutes");
				                puts("3) Hours");
							    if(menu12=4)
			                      {
				                   int menu16;
			                       scanf("%d",&menu16);
			                       switch(menu16)
				                      {
				                       case 1:
				                              puts("Please enter Days");
				                              scanf("%f",&d);
				                              s=d*86400;
				                              printf("%.2f Days are %.2f Seconds\n", d,s);
				                              break;
				                        case 2:
				                               puts("Please enter Days");
				                               scanf("%f",&d);
				                               min=d*1440;
				                               printf("%.2f Days are %.2f Minutes\n",d,min);
				                               break;
				                        case 3:
				                               puts("Please enter Days");
				                               scanf("%f",&d);
				                               h=d*24;
				                               printf("%.2f Days are %.2f Hours\n", d,h);
				                               break;
			                            }
					               }
				                break;}
}
};