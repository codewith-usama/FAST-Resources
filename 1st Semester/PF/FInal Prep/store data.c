#include<stdio.h>
int main()
{
	FILE *fptr;
	fptr = fopen("store.txt", "w");
	char arr[20];
	
	printf("Enter a String: ");
	
	gets(arr);
	fprintf(fptr, "%d", arr);
}
