#include<stdio.h>
#include<string.h>
char Revers_of_string()
{
	int arr[100], rev[100];
	printf("Enter a string: ");
	gets(arr);
	printf("Enter second string: ");
	gets(rev);
	int l;
	strrev(rev);
	strcmp(arr,rev);
	l=strcmp(arr,rev);
	if(l==0)
	printf("string is palindrom");
	else 
	printf("String is not palindrom");
}
main()
{
	Revers_of_string();
}
