#include<stdio.h>
struct employee
{
	int salary;
}e[10];
int main()
{
	int i, sum = 0;
	float avg;
	for(i = 1; i <= 10; i++)
	{
		printf("Enter salary of %d employee: ",i);
		scanf("%d", &e[i].salary);
		sum = e[i].salary;
	}
	avg = sum/10;
	printf("The sum of employee salary is %.2f", avg);
	printf("The size of structre employee is %d", sizeof(e[10]));
}
