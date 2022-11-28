#include <stdio.h>
#include <string.h>

void func(char name[], int index);
int main()
{
	char name[10];
	printf("Enter a string: ");
	gets(name);
	func(name,0);
}

void func(char name[], int index)
{
	int len = strlen(name) - (index + 1);
	if(name [index] == name[len])
	{
		if(index == len || index + 1 == len)
		{
			printf("Palidrom.");
			return;
		}
		func(name, index+1);
	}
		else
		printf("Not Palindrom.");
}
