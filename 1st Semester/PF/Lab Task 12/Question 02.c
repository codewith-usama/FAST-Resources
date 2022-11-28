#include <stdio.h>
int main()
{
	char arr[100];
	FILE *fptr;
	fptr = fopen("My File.txt", "w");
	system("color 0A");
	printf("Enter a sentence: ");
    gets(arr);
  	fputs(arr,fptr);
	
	fclose(fptr);
}
