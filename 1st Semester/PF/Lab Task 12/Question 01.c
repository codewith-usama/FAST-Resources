#include <stdio.h>
struct student
{
	char name[100];
	int marks;
};

int main()
{
	FILE *fptr;
	fptr = fopen("File.txt", "w"); 
	system("color 0A");
	
	int n, i;
	printf("Enter Number of students: ");
	scanf("%d", &n);
	
	system("Cls");
	
	
	struct student s[n];

	for(i = 1; i <= n; i++)
	{
		printf("Input Data of %d Students\n", n);
		printf("\nEnter Student %d Name: ", i);
		scanf("%s", s[i].name);
		printf("Enter Student %d Makrs: ", i);
		scanf("%d", &s[i].marks);
		fprintf(fptr, "%d. Name: %s \n   Marks: %d\n", i, s[i].name, s[i].marks);
		system("Cls");
	}
	
	system("Cls");
	
fclose(fptr);	


	fptr = fopen("File.txt", "r");
	char store[100];
	
	if(fptr ==  NULL)
	{
		puts("Error");
	}
	
	fscanf(fptr,"%[^\0]", store );
	printf("%s",store);
	
}
