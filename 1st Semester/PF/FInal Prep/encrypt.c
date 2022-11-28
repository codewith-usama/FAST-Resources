#include<stdio.h>
int main()
{
	FILE *fptr;
	char filename[10];
	printf("Enter name:");
	gets(filename);
	
	fptr = fopen(filename, "w");
	char text[10];
	printf("Enter some text:");
	gets(text);
	int k;
	printf("Enter a key: ");
	scanf("%d", &k);
	
	char store[10];
	int i;
	for(i=0; i<strlen(text); i++)
	{
		store[i]= text[i] + k;
	}
	
	for(i=0; i<strlen(text); i++)
	{
		printf("%c", store[i]);
	}
}
