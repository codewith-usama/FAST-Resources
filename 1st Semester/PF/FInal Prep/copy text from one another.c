#include<stdio.h>
#include<stdlib.h>

main()
{
	char file1[100], file2[100], ch;
	FILE *fptr1, *fptr2;
	printf("Enter File 1 Name: ");
	gets(file1);
	fptr1 = fopen(file1, "r");
	
	if(fptr1 == NULL)
	{
		puts("Error in opening File");
	}
	
	printf("Enter File 2 Name: ");
	gets(file2);
	
	fptr2 = fopen(file2, "a");
	
	while(1)
	{
		ch = fgetc(fptr1);
		
		if(ch != EOF)
		{
			fputc(ch, fptr2);
		}
		else
		{
			break;
		}
	}
		
	printf("Data copied.");
	fclose(fptr1);
	fclose(fptr2);
	
	
}
