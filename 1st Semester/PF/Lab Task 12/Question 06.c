#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	FILE *fptr;
	fptr = fopen("Encrypt.txt", "w");
	system("color 0A");
	
	if(fptr ==  NULL)
	{
		puts("Error");
	}
	char text[100];
	char store[100];
	int k, i;
	
	printf("Enter Some Text: ");
	gets(text);
	
	printf("Enter a key: ");
	scanf("%d", &k);
	
	for(i = 0; i < strlen(text); i++)
	{
		store[i] = text[i] + k;
	}
	printf("The Encrypted text is: ");
	
	for(i = 0; i < strlen(text); i++)
	{
		printf("%c", store[i]);
		fprintf(fptr, "%c", store[i]);
	}
	
	fclose(fptr);
	
	int p;
	printf("\nPress 1 for Decrypt the data: ");
	scanf("%d", &p);
	
	if(p == 1)
	{
	system("cls");
	
	fptr = fopen("Encrypt.txt", "r");
	
	fscanf(fptr,"%[^\0]", &store);
	printf("\nThe data in file is %s", store);
	
	printf("\nEnter a key: ");
	scanf("%d", &k);
	
	char store1[100];
	printf("The Decrypted text is: ");
	for(i = 0; i < strlen(store); i++)
	{
		store1[i] = store[i] - k;
		printf("%c", store1[i]);
	}
	
//	for(i = 0; i < strlen(store); i++)
//	{ 
//		
//	}
}
	fclose(fptr);
}
