#include<stdio.h>
main()
{
	int sum=0, n, counter;
	printf("Enter any number:");
	scanf("%d", &n);
	
	while(n>=200 && n<=400)
	{
		sum=sum+n;
		counter++;
		printf("Enter any number:");
		scanf("%d", &n);
	}
	printf("The sum of number is %d", sum);
}
