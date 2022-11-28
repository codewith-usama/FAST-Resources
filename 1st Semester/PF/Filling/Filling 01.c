#include<stdio.h>

// Mode: Text and Binary
// Operations: Read, Write,...

int main()
{
	FILE *fptr;
	fptr = fopen("My File.txt", "r");
	
	if(fptr == NULL)
	{
		printf("Error");
	}
	else 
	{
		char txt[50];
		fscanf(fptr,"%[^\0]", &txt);
		printf("%s", txt);
	
		fclose(fptr);
	}
	
	
	
	
	
//	int iwrite = 10;
//	fprintf(fptr, "%d", iwrite);
	
//	int i;
//	char c;
//	for(i = 0; i <= 50; i++)
//	{
//		fscanf(fptr,"%c", &c);
//		printf("%c",c);
//	}
	
	
	fclose(fptr);
}
