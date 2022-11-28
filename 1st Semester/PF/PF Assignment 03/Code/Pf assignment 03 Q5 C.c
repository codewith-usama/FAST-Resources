#include<stdio.h>
main()
{
	int n, i, j;
	printf("Enter number of rows:");
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==n)
			printf(" %d", j);
			else if(j==1 || j==i)
			printf(" %d", j);
			else
			printf(" ");
		}
		printf("\n");
	}
	printf("\n Hollow half Pyrmid");
}
