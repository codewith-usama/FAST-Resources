#include <stdio.h>
Revers_of_String()
{
	char arr[10];
	printf("Enter A string: ");
	gets(arr);
	int i, x=strlen(arr);
	for(i=x-1; i>=0; i--)
	{
		printf("%c", arr[i]);
	}
}
int main()
{
	Revers_of_String();
}	
