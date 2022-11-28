#include <stdio.h>

struct employee
{
	char name[10];
	int ID;
};


int main()
{
	FILE *fptr;
	fptr = fopen("struct file.bin", "wb");
	if(fptr == NULL)
	{
		puts("Error in File");
		exit(1);
	}
	
	int i;
	int  n;
	printf("Enter Number of Employees: ");
	scanf("%d", &n);
	
	struct employee e[n];
	
	for(i = 0; i < n; i++)
	{
		
		printf("\nEnter Employee name: ");
		scanf("%s", e[i].name);
		printf("Enter Employee ID: ");
		scanf("%d", &e[i].ID);
		fwrite(&e[i], sizeof(struct employee), 1, fptr);
		//fflush(stdin);
	}	
	fclose(fptr);
	system("cls");
	
	fptr = fopen("struct file.bin", "rb");
	for(i = 0; i < n; i++)
	{
		fread(&e[i], sizeof(struct employee), 1, fptr);	
		printf("Name: %s", e[i].name);
		printf(" > ID: %d\n", e[i].ID);
	}
	fclose(fptr);	
	
}
