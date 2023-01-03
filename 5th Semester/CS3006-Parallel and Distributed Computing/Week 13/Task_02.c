#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>

void merge(int *a, int *b, int l, int m, int r) {
	int h, i, j, k;
	h = l;
	i = l;
	j = m + 1;
	
	while((h <= m) && (j <= r)) {
		if(a[h] <= a[j]) {
			b[i] = a[h];
			h++;
		}	
		else {
			
			b[i] = a[j];
			j++;			
		}			
		i++;	
	}
		
	if(m < h) {
	
		for(k = j; k <= r; k++) {		
			b[i] = a[k];
			i++;
		}	
	}	
	else {
		for(k = h; k <= m; k++) {			
			b[i] = a[k];
			i++;
		}
			
	}
		
	for(k = l; k <= r; k++)
		a[k] = b[k];
		
}
void mergeSort(int *a, int *b, int l, int r) {
	
	int m;	
	if(l < r) {
		m = (l + r)/2;
		mergeSort(a, b, l, m);
		mergeSort(a, b, (m + 1), r);
		merge(a, b, l, m, r);	
	}
		
}

int main(int argc, char** argv) {
	int n = 10;
	int *array = malloc(n * sizeof(int));
	
	int c;
	printf("This is the uns array: ");
	for(c = 0; c < n; c++) {	
		array[c] = rand() % n;
		printf("%d ", array[c]);
	}

	printf("\n\n");
	int myrank;
	int mysize;
		
    MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &mysize);
	int size = n/mysize;
	int *array1 = malloc(size * sizeof(int));
	MPI_Scatter(array, size, MPI_INT, array1, size, MPI_INT, 0, MPI_COMM_WORLD);
	int *array2 = malloc(size * sizeof(int));
	mergeSort(array1, array2, 0, (size - 1));
	int *s = NULL;
	if(myrank == 0)
		s = malloc(n * sizeof(int));
	
	MPI_Gather(array1, size, MPI_INT, s, size, MPI_INT, 0, MPI_COMM_WORLD);
	if(myrank == 0) {
		int *array3 = malloc(n * sizeof(int));
		mergeSort(s, array3, 0, (n - 1));
		printf("This is the s array: And I am Process %d --->  ",myrank);
		for(c = 0; c < n; c++)		
			printf("%d ", s[c]);
			
		printf("\n\n");			
	}
	
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();
	
}

