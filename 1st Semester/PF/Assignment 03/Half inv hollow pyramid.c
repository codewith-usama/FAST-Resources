#include<stdio.h>
int main()
{
	int i,j,k,n;
	printf("Enter number of rows:");
	scanf("%d", &n);
	for (k=1;k<=n;k++)
	printf("%d ",k);
	printf("\n");
	for (i=n-1;i>=1;i--)
	{
		for(j=1;j<=i;j++)
		{
		if (j == 1 || j == i || i == n)
		printf("%d ",j);
		else
		printf("  ");
		}
	printf(" \n");
	}
}
