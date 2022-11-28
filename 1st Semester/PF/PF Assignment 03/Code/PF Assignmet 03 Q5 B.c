#include<stdio.h>
main()
{
	int i,j, n;
	printf("Enter number of row:");
	scanf("%d", &n);
	for(i=n;i>=1;i--)
	{
		for(j=1;j<=i;j++)
		{
			printf(" %d", j);
		}
		printf("\n");
	}
	printf("\n Reverted Pyramid");
}
