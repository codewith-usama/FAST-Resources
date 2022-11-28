#include <stdio.h>
int main()
{
	FILE *fptr;
//	fptr = fopen("write file.txt", "w");
	fptr = fopen("write file.txt", "a");
	
	int iwrite = 1;
	//fscanf(fptr, "%d", &iwrite);
	fprintf(fptr, "%d", iwrite);
	
	fclose(fptr);
	
	
		
//	int iwrite = 20;
//	int iwrite1 = 10;
//	fprintf(fptr, "%d", iwrite);
//	fprintf(fptr, "\n%d", iwrite1);	
//	
	
}
