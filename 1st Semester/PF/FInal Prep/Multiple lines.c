#include<stdio.h>
int main()
{
	FILE *fptr;
	fptr = fopen("multi.txt", "w");
	char arr[40];
	int l, i;
	printf("Enter number of lines: ");
	scanf("%d", &l);
	l++;
	
	for(i = 1; i < l+1; i++)
	{
//		printf("Enter %d line: ",i);
		fgets(arr, sizeof arr, stdin);
		fputs(arr, fptr);
//		printf("\n\n");
	}
	fclose(fptr);
	
	fptr = fopen("multi.txt", "r");
	char arr1[40];
	
	fscanf(fptr, "%[^\0]", arr1);
	puts(arr1);
	
	fclose(fptr);
}
