#include <stdio.h>
#include <string.h>
int main()
{
	char arr[10];
	char ch;
	int sum = 0, i;
	printf("Enter an Array: ");
	gets(arr);
	for(i=0;i<strlen(arr);i++)
	{
		if(arr[i] == '4')
		sum++;
	}
	printf("Number of 4 in array is: %d", sum);
	
}
