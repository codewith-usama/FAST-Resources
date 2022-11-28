#include <stdio.h>
main()
{
	int n;
	puts("Enter Number of Elements you want to allocate: ");
	scanf("%d", &n);
	char * arr = calloc(n, sizeof(char));
	int i;
	char ch;
	for(i = 0; i < n; i++)
		arr[i]=ch+i;
	for(i = 0; i < n; i++)
		printf("Value of arr[%d] : %c\n", i, arr+i);		
}
