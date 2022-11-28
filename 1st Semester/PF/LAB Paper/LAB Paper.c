#include<stdio.h>  
#include<string.h>
#include<stdlib.h>

struct Employee
{
	int salary, age, Emp_id;
	char Emp_name[20];
};
struct Department 
{
	char depart_name[10];
	int depart_id;
};
void func(char Emp_name[], int salary);
int main()
{
	FILE *fptr;
//	fptr = fopen("Paper.txt", "w");
	int x=5, i;
	
	struct Employee e[x];
	struct Department d[x];
	
//	for(i = 1; i <= 5; i++)
//	{
//		printf("Enter ID of Employee %d: ", i);
//		scanf("%d", &e[i].Emp_id);
////		fprintf(fptr, "%d: Employee ID -> %d",i, e[i].Emp_id);
//		
//		
//		printf("Enter Name of Employee %d: ", i);
//		scanf(" %[^\n]", e[i].Emp_name);
////		fprintf(fptr, "%d: Name -> %s",i, e[i].Emp_name);
//		
//		printf("Enter Salary of Employee %d: ", i);
//		scanf("%d", &e[i].salary);
////		fprintf(fptr, "%d", e[i].salary);
//		
//		printf("Enter Age of Employee %d: ", i);
//		scanf("%d", &e[i].age);
////		fprintf(fptr, "%d", e[i].age);
//		
//		printf("Enter Department of Employee %d: ", i);
//		scanf(" %[^\n]", &d[i].depart_name);
////		fprintf(fptr, "%s", d[i].depart_name);
//		
//		printf("Enter Department ID of Employee %d: ", i);
//		scanf("%d", &d[i].depart_id);
////		fprintf(fptr, "%d", d[i].depart_id);
//		fprintf(fptr, "%d: Employee ID -> %d  Name -> %s  Salary -> %d  Age -> %d  Department -> %s  Deprt ID -> %d\n\n",i, e[i].Emp_id, e[i].Emp_name, e[i].salary, e[i].age, d[i].depart_name, d[i].depart_id );
//		system("cls");
//	}
//	fclose(fptr);
//	
	fptr = fopen("Paper.txt", "r");
	
	char store[1000];
	
	if(fptr ==  NULL)
	{
		puts("Error");
	}
	
	fscanf(fptr,"%[^\0]", store);
	puts(store);
	
	fclose(fptr);
	char ch=d[i].depart_name;
	int var=e[i].salary;
	func(ch, var);
}
void func(char ch[], int var)
{
	char ch1;
	ch1 = ch;
	if(ch1 == 'y')
	{
		printf("%s", ch);
		return ch; 
	}
	
//	replace(ch)	
}

