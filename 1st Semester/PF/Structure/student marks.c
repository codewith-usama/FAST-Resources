#include<stdio.h>
struct student
{
	char name[10];
	int rollnum, attendmark, t1, t2, t3;
} s1, s2;
int main()
{
	system("cls");
	int i;
	for(i = 1; i <= 2; i++)
	{
		printf("Enter %d student Name: ", i);
		scanf("%s", s1[i].name);
		printf("Enter Roll Num: ");
		scanf("%d", &s1[i].rollnum);
		printf("Enter attendence marks: ");
		scanf("%d", &s1[i].attendmark);
		printf("Enter Test 1 Marks: ");
		scanf("%d", &s1[i].t1);
		printf("Enter Test 2 Marks: ");
		scanf("%d", &s1[i].t2);
		printf("Enter Test 3 Marks: ");
		scanf("%d", &s1[i].t3);
		
		printf("Enter %d student Name: ", i);
		scanf("%s", s2[i].name);
		printf("Enter Roll Num: ");
		scanf("%d", &s2[i].rollnum);
		printf("Enter attendence marks: ");
		scanf("%d", &s2[i].attendmark);
		printf("Enter Test 1 Marks: ");
		scanf("%d", &s2[i].t1);
		printf("Enter Test 2 Marks: ");
		scanf("%d", &s2[i].t2);
		printf("Enter Test 3 Marks: ");
		scanf("%d", &s2[i].t3);
	}
	
}
