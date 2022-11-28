#include <stdio.h>

int main()
{
	int *arr = calloc(6, sizeof(int));
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		printf("Number %d: ", i+1);
		scanf("%d", (arr + i));
	}
	
	int min = *arr;
	printf("%d\n", *arr);
	int index = 0;
	for (i = 0; i < 6; i++)
	{
		if ((*(arr + i) ) <  min)
		{
			min = *(arr + i);
			index = i;
		}
 	}
 	printf("The smallest number is %d at index %d", min, index);
	
}
