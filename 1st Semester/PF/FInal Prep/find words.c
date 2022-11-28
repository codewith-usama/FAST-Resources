#include<stdio.h>
int main()
{
	FILE *fptr;
	
//	fptr = fopen("words.txt", "r");	
//	char arr[50];
//	fscanf(fptr, "%[^\0]", arr);
//	puts(arr);
//	fclose(fptr);
	
	fptr = fopen("words.txt", "r");
	
	if(fptr == NULL)
	{
		puts("Error");
	}
	
	
	char ch;
	int character = 0;
	int words = 0;
	
	ch = getc(fptr);
	
	while(ch != EOF)
	{
		printf("%c", ch);
		
		if(ch == ' ' || ch == '\n')
		{
			words++;
		}
		else
		{
			character++;	
		}
		ch = getc(fptr);
	}
	
	printf("\nNumber of words in text file is %d", words - 1);
	printf("\nNumber of characters in text file is %d", character);
	fclose(fptr);
	
	
}
