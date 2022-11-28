#include<stdio.h>
struct student 
{
	char name[20];
	int marks;
};

int main()
{
	FILE *fptr;
	fptr = fopen("New.txt", "w");
	int n, i;
	printf("Enter the number of student: ");
	scanf("%d", &n);	
	struct student s[n];
	
	for(i = 1; i <= n; i++)
	{
		printf("Enter student name: ");
		scanf("%s", s[i].name);
		printf("enter student marks: ");
		scanf("%d", &s[i].marks);
		fprintf(fptr, "%s  %d", s[i].name, s[i].marks);
	}
	fclose(fptr);
	fptr = fopen("New.txt", "r");
	if(fptr == NULL)
	{
		puts("Error");
	}
	
	for(i = 1; i <= n; i++)
	{
		printf("Enter student name: ");
		scanf("%s", s[i].name);
		printf("enter student marks: ");
		scanf("%d", &s[i].marks);
		fprintf(fptr, "%s  %d", s[i].name, s[i].marks);
	}
}
