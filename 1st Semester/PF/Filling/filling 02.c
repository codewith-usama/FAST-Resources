#include<stdio.h>
int main()
{
	FILE *fptr;
	fptr=fopen("My File 02.txt", "r");
	
	char iread[50];
	fscanf(fptr, "%[^\0]", &iread);
	puts(iread);
	fclose(fptr);
	
}
