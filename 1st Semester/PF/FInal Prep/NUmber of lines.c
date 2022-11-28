#include<stdio.h>
int main()
{
	FILE *fptr;
	
	fptr = fopen("num.txt", "r");
	
	char arr[50];
	fscanf(fptr, "%[^\0]", arr);
	puts(arr);
	
	fclose(fptr);
	
	fptr = fopen("num.txt", "r");
	
	if(fptr == NULL)
	{
		puts("Error");
	}
	
	
	char ch;
	int num = 0;
	
	ch = getc(fptr);
	
	while(ch != EOF)
	{
		if(ch == '\n')
		{
			num++;
		}
		ch = getc(fptr);
	}
	
	printf("\nNumber of lines in text file is %d", num);
	
	fclose(fptr);
	
	
}
