#include <stdio.h>
main()
{
	int n;
	printf("Enter Number of element you want to order: ");
	scanf("%d", &n);
	
	int *arr = calloc(n, sizeof(int));
	int i;
	
	for(i = 0; i < n; i++);
		arr[i]=i;
		n = 10;
		arr = realloc(arr, n * sizeof(int));

	for(i = 5; i < n; i++)
		arr[i]=i;
	printf("Arr[10] = ");
	for(i = 0; i < n; i++)
	printf("[%d], ", i, arr[i]);
	
	free(arr);
}
