#include<stdio.h>
#include<string.h>

struct student
{ 
	int ID;
	char name[10];
}; 

func(struct student *ptr);

int main()
{ 
	struct student var[2];
	struct student *ptr;
	ptr = var;
	func(var);		
	printf("First index = %d Name = %s", var[0].ID, var[0].name);
	printf("Second index = %d Name = %s", var[1].ID, var[1].name);
} 
func(struct student *ptr)
{
	int i;
	for( i = 0; i < 2; i++)
	{
		printf("Enter Emp ID :");
		scanf("%d", &(ptr+i)->i);
		printf("Enter Emp name: ");
		scanf("%s",&(ptr+i)->i);
	}
}
