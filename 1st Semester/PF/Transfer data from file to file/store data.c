#include<stdio.h>
int main()
{
	FILE *fptr;
	fptr = fopen("store.txt", "w");
	char arr[20];
	
	printf("Enter a String: ");
	
	gets(arr);
	fprintf(fptr, "%s", arr);
	fclose(fptr);
	
	fptr = fopen("store.txt", "r");
	
	if(fptr == NULL)
	{
		puts("Error in opening file");
	}
	
	char store[30];
	fscanf(fptr, "%[^\0]", store);
	puts(store);
	fclose(fptr);
	
}
