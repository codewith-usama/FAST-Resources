#include<stdio.h>
#include<stdio.h>
int func(char arr[]);
int main()
{
	char arr[20];
	int x = 0;
	printf("Enter a string: ");
	gets(arr);
	x = func(arr);
	printf("Number of identical letters in words are : %d", x);
}
int func(char arr[])
{
	static i = 0,j, count = 0;
	if(i == strlen(arr))
	return count;
	j=i;
	for(j;j<strlen(arr);j++)
	{
	if(arr[i] == arr[j + 1]) // attack
	count++;
	}
	i++;
	func(arr);
}
