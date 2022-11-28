#include <stdio.h>
int main()
{
	FILE *fptr;
	fptr = fopen("Reading file.txt", "r");
	
	char iread[20];
	//char c;
	
	fseek(fptr, 3, SEEK_CUR);
	fscanf(fptr, "%[^\0]", &iread);
	printf("%s", iread);
	
	
	fclose(fptr);
}
