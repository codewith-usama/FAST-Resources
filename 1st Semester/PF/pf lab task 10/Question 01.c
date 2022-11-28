#include<stdio.h>
#include<string.h>

struct student
{
	char name[100]; 
	int rollnum[10], attendencemarks[10], test01[10], test02[10], test03[10];
}
s1;
int main()
{
	int std, i;
	system("Color 0A");
	printf("Enter number of student:");
	scanf("%d", &std);
	system("cls");
	for(i=1;i<=std;i++)
	{
		printf("\nEnter the Name: "),
		scanf("%s", &s1.name);
		printf("Enter Roll Number: ");
		scanf("%d", s1.rollnum);
		printf("Enter Attendence Marks: ");
		scanf("%d", s1.attendencemarks);
		printf("Enter Marks of test 1: ");
		scanf("%d", s1.test01);
		printf("Enter Marks of test 2: ");
		scanf("%d", s1.test02);
		printf("Enter Marks of test 3: ");
		scanf("%d", s1.test03);
	
	}
}
