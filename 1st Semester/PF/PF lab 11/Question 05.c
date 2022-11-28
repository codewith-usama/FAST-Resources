#include <stdio.h>

int main() 
{
	int size_of_toy;
	int approx_size;
	printf("Enter approx size: ");
	scanf("%d", &approx_size);
	printf("Enter size of toy: ");
	scanf("%d", &size_of_toy);
	int *toy = calloc(approx_size, sizeof(float));
	printf("%d\n", sizeof(toy));
	toy = realloc(toy, size_of_toy * sizeof(float));
	printf("%d\n", sizeof(toy));
}
