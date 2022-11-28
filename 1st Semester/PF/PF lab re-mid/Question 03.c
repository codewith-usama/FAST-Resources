#include <stdio.h>
int main()
{
	int s, HRA, DA, HRA1, DA1;
	int gs, gs1;
	printf("Enter the Basic Salary of Employee: ");
	scanf("%d", &s);
	if(s < 1500)
	{
		HRA = s*0.1;
		DA = s*0.9;
		gs = HRA + DA + s;
		printf("The Gross Salary of Employee is: %d", gs);
		return 0;
	}
	else
		HRA1 = 500;
		DA1 = s*0.98;
		gs1 = HRA1 + DA1 + s;
		printf("The Gross Salary of Employee is: %d", gs1);
	
}
