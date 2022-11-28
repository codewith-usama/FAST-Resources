#include <stdio.h>
int main()
{
    int i, j, n, count = 0, count1 = 0, k = 0;
	printf("Enter rows of pyramid:");
	scanf("%d",&n);
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= n-i; ++j)
    {
		printf("  ");
		++count;
	}

	while(k != 2*i-1)
	{
		if (count <= n-1)
		{
			printf("%d ", i+k);
			++count;
		}
		else
		{
		++count1;
		printf("%d ", (i+k-2*count1));
		}
		++k;
	}
	count1 = count = k = 0;

	printf("\n");
	}
	printf(" Full Pyramid");
	return 0;
}
