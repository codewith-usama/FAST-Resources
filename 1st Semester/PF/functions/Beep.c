#include<stdio.h>
void beep(void);
int i, rows;
void main(void)
{
	printf("Enter number of rows: ");
	scanf("%d", &rows);
	printf("\nTesting Of UDF..");
	for(i=1;i<=rows;i++)
	{
		beep();		
	}
}
void beep(void)
{
	printf("\na");
}

