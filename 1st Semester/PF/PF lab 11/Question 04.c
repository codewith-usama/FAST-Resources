#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,j,k=1;
	int sum = 0;
	printf("Enter the number of student in your class : ");
	scanf("%d", &n);
	int *arr = calloc(n, sizeof(int));
	for ( i = 0; i < n; i++)
	{
		printf("Enter marks of student %d: ", k);
		scanf(" %d", (arr + i) );
		k++;
		sum = sum + (*(arr + i));
	}
	float avg = (float )sum / (float)n;
	int temp;
	for (i = 0; i < n; i ++)
	{
		for ( j = 0; j < n - 1; j++)
		{
			if (*(arr + j) < *(arr + j + 1))
			{
				temp =	*(arr + j);
				*(arr + j ) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
	
	printf("Highest Marks : %d\nSecond Highest : %.2d\nAvg : %f\nSum : %d\n", *arr, *(arr + 1), avg, sum);
	free(arr);
}
