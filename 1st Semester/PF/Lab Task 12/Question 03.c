#include <stdio.h>
int main()
{
	FILE *fptr;
	fptr = fopen("Read data.txt", "r");
	char ch[1000];
	char n;
	int nol = 1;
	
	n = getc(fptr);
	while(n != EOF)
	{
		if(n == '\n')
		{
			++nol;  // "nol" is number of lines
		}
		n = getc(fptr);
	}
	
	fclose(fptr);
	system("color 0A");
	printf("%d lines in the Text File.",nol);
	
	
}
