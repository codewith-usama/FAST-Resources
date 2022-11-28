#include<stdio.h>
#include<string.h>
char Revers_of_string()
{
	char a[100];
	printf("Enter a string: ");
	scanf("%s", &a);
	int i, x=strlen(a);
	for(i=x-1;i>=0;i--)
	
		printf("%c",a[i]);
}
main()
{
	Revers_of_string();
}
