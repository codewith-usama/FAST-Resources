#include<stdio.h>
typedef struct
{
	short int day;
	int month, year;
}
Date;
int main()
{
	Date date1, date2;
	printf("Enter date 1 Format dd/mm/yy: ");
	scanf("%d/%d/%d", &date1.day,&date1.month,&date1.year);
	
	printf("Enter date 2 Format dd/mm/yy: ");
	scanf("%d/%d/%d", &date2.day,&date2.month,&date2.year);
	
	if((date1.day==date2.day)&&(date1.month==date2.month)&&(date1.year==date2.year))
	printf("Dates are Equal.");
	else
	printf("Dates are not Equal.");
	
}
