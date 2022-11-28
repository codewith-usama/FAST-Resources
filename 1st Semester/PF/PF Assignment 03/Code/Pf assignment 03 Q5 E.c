#include<stdio.h>
main()
{
	int n, i, j;
	printf("Enter number of rows:");
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		for(j=i;j<n;j++)
		{
			printf("  ");
		}
		for(j=1;j<=(2*i);j++)
		{
			if(i==n || j==1 || j==(2*i-1))
			printf(" %d", j);
			else
			printf("  ");
		}
		printf("\n");
	}
	printf("Hollow full Pyramid");
}
