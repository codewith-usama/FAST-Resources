#include<stdio.h>
int main()
{
	FILE *fptr1, *fptr2, *fptr3;
	fptr1 = fopen("1 File.txt", "r");
	if(fptr1 == NULL)
	{
		puts("Error in opening file");
	}
	
	fptr3 = fopen("3 File.txt", "w");
	char ch;
	
	while(1)
	{
		ch = fgetc(fptr1);
		if(ch != EOF)
		{
			fputc(ch, fptr3);	
		}
		else
		break;	
	}
	fclose(fptr1);
	fclose(fptr3);
	
	fptr3 = fopen("3 File.txt", "a");
	
	fptr2 = fopen("2 File.txt", "r");
	if(fptr2 == NULL)
	{
		puts("Error in opening file");
	}
	
	while(1)
	{
		ch = fgetc(fptr2);
		if(ch != EOF)
		{
			fputc(ch, fptr3);	
		}
		else
		break;	
	}
	fclose(fptr3);
	fclose(fptr2);	
}
