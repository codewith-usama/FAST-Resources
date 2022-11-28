#include<stdio.h>
struct employee
{
	int salary;
};
int main()
{
	struct employee b[10];
	int i, j;
	float sum=0, avg;
	for(i=1;i<=10;i++)
	{
		printf("Enter salary of Employee %d: ", j);
		j++;
		scanf("%d", &b[i].salary);
		sum=sum+b[i].salary;
	}
	avg=sum/10;
	printf("\nAverage of the Employees' Salary is %.2f", avg);
}
