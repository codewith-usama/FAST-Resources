#include<stdio.h>
#include<string.h>
char reverse_of_string()
{
	char arr[1000];
	
	printf("Enter a String: ");
	
	gets(arr);
	
	int i,x=strlen(arr);
	
	for (i=x-1;i>=0;i--)
	{
		
		printf("%c",arr[i]);
	}
	
}


int main(){

	reverse_of_string();	
}
