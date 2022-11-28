#include<stdio.h>
struct date
{
	int day, month, year;
}d1, d2;
int main()
{
	printf("Enter a Date format(dd/mm/yy): ");
	scanf("%d/%d/%d", &d1.day, &d1.month, &d1.year);
	printf("Enter another Date to compare format(dd/mm/yy): ");
	scanf("%d/%d/%d", &d2.day, &d2.month, &d2.year);
	if(d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
	puts("Dates are equal");
	else
	puts("Dates are not equal");
}
