#include<stdio.h>
#include <string.h>
void string(char name[], int index);

int main()
{
	char name[20];
	printf("Enter A Name: ");
	gets(name);
	string(name, 0);
}

void string(char name[], int index)
{
	int i, len;
	for(i = 0; i < strlen(name); i++)
	{
		 len = strlen(name) - (index+1);
			if(name[index] == name[len])
			{
				if(index == len || index + 1 == len)
				{
					puts("Palidrom.");
					return;
				}	
			}
			else
			{
				puts("Not Palindrom.");
				return;
			}
			index++;
	}
}
