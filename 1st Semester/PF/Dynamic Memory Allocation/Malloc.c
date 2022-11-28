#include<stdio.h>

    // Dynamic Memory Allocation
    //Malloc, Calloc, Realloc, Free
    
int main()
{
	int n;
	puts("Enter number of elements you want to allocate: ");
	scanf("%d", &n);
	
	int * arr = malloc(n*sizeof(int));
	int i;
	for(i = 0; i < n; i++)
		arr[i]=i;	
	for(i = 0; i < n; i++)
		printf("arr[%d] : %d\n", i, arr[i]);
	
	
	
	
	
	
//	int * arr = malloc(40);
//	int i;
//	for(i = 0; i < 10; i++)
//		arr[i]=i;
//	for(i = 0; i < 10; i++)
//		printf("arr[%d] : %d\n", i, arr[i]);	
}
