#include<stdio.h>
main()
{
	int n, j=1;
	do
	{
		if(n>=200 || n<=400)
		{
			printf("Enter number:1", j);
			j++;
			scanf("%d", &n);	
		}
	}
}
