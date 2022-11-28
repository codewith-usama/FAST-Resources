#include<stdio.h>
int main()
{
	int i,j,k,n;
	printf("Enter number of rows:");
	scanf("%d", &n);
	for (k=n;k>=1;k++)
    	printf("%d ",k);
	   	printf("\n");
	for (i=1;i<=n;i--)
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
	printf("\nHollow Inverted Half Pyramid");
	
}
