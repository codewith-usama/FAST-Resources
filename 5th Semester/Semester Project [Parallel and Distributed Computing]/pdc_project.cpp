#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>
#include <omp.h>
#include <iostream>
#include <string>


typedef double TYPE;
#define DIM 2000
#define MAX_DIM DIM*DIM
#define SDIM 500
#define IDIM 500

// Method signatures
TYPE** randomSquareMatrix(int dimension);
TYPE** zeroSquareMatrix(int dimension);
void displaySquareMatrix(TYPE** matrix, int dimension);
void convert(TYPE** matrixA, TYPE** matrixB, int dimension);

void sequentialMultiplyTest(int dimension);
void parallelMultiplyTest(int dimension);
void optimizedParallelMultiplyTest(int dimension);


double sequentialMultiply(TYPE** matrixA, TYPE** matrixB, TYPE** matrixC, int dimension);
double parallelMultiply(TYPE** matrixA, TYPE** matrixB, TYPE** matrixC, int dimension);
double optimizedParallelMultiply(TYPE** matrixA, TYPE** matrixB, TYPE** matrixC, int dimension);


TYPE flatA[MAX_DIM];
TYPE flatB[MAX_DIM];

int main(){
	
	FILE* fp;
	fp = fopen("SequentialMultiplyTest.txt", "w+");
	fclose(fp);
	
	fp = fopen("ParallelMultiplyTest.txt", "w+");
	fclose(fp);
	
	fp = fopen("ParallelMultiplyTestLocalResult.txt", "w+");
	fclose(fp);

	fp = fopen("OptimizedParallelMultiplyTest.txt", "w+");
	fclose(fp);
	
	fp = fopen("OptimizedParallelMultiplyTestLocalResult.txt", "w+");
	fclose(fp);
	
	
	for(int dimension=SDIM; dimension<=DIM; dimension+=IDIM){
		optimizedParallelMultiplyTest(dimension);
	}

	for(int dimension=SDIM; dimension<=DIM; dimension+=IDIM){
		parallelMultiplyTest(dimension);
	}

	for(int dimension=SDIM; dimension<=DIM; dimension+=IDIM){
		sequentialMultiplyTest(dimension);
	}

	return 0;
}


double sequentialMultiply(TYPE** matrixA, TYPE** matrixB, TYPE** matrixC, int dimension){
	
	FILE* fp;
	fp = fopen("SequentialMultiplyTest.txt", "a+");
	
	double st=omp_get_wtime();
	for(int i=0; i<dimension; i++){
		for(int j=0; j<dimension; j++){
			for(int k=0; k<dimension; k++){
				matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
	
	double en=omp_get_wtime();
	double elapsed = en-st;

	return elapsed;
}


double parallelMultiply(TYPE** matrixA, TYPE** matrixB, TYPE** matrixC, int dimension){

	int i, j, k;	

	double st=omp_get_wtime();
	
	FILE* fp;
	fp = fopen("ParallelMultiplyTestLocalResult.txt", "a+");

	fprintf(fp, "----------------------------------\n");
	fprintf(fp, "Test : Optimized Parallel Multiply\n");
	fprintf(fp, "----------------------------------\n");
	fprintf(fp, "Dimension : %d\n", dimension);
	fprintf(fp, "..................................\n");
	
	#pragma omp parallel shared(matrixC) private(i, j, k) num_threads(8)
	{
		#pragma omp for
		for(int i=0; i<dimension; i++){
			for(int j=0; j<dimension; j++){
				for(int k=0; k<dimension; k++){
					matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
				}
			}
		}
		fprintf(fp, "\nFrom thread %d ", omp_get_thread_num());
		fprintf(fp, "\n");
		for(int i=0; i<dimension; i++){
			for(int j=0; j<dimension; j++){
				fprintf(fp, "%1.0f\t", matrixC[i][j]);
			}
			fprintf(fp, "\n");
		}
	}

	double en=omp_get_wtime();
	double elapsed = en-st;	

	return elapsed;
}

double optimizedParallelMultiply(TYPE** matrixA, TYPE** matrixB, TYPE** matrixC, int dimension){

	int i, j, k, iOff, jOff;
	TYPE tot;

	double st=omp_get_wtime();
	
	FILE* fp;
	fp = fopen("OptimizedParallelMultiplyTestLocalResult.txt", "a+");

	fprintf(fp, "----------------------------------\n");
	fprintf(fp, "Test : Optimized Parallel Multiply\n");
	fprintf(fp, "----------------------------------\n");
	fprintf(fp, "Dimension : %d\n", dimension);
	fprintf(fp, "..................................\n");
	
	convert(matrixA, matrixB, dimension);
	#pragma omp parallel shared(matrixC) private(i, j, k, iOff, jOff, tot) num_threads(8)
	{
		#pragma omp for 
		for(i=0; i<dimension; i++){
			iOff = i * dimension;
			for(j=0; j<dimension; j++){
				jOff = j * dimension;
				tot = 0;
				for(k=0; k<dimension; k++){
					tot += flatA[iOff + k] * flatB[jOff + k];
				}
				matrixC[i][j] = tot;
			}
		}
		fprintf(fp, "\nFrom thread %d ", omp_get_thread_num());
		fprintf(fp, "\n");
		for(int i=0; i<dimension; i++){
			for(int j=0; j<dimension; j++){
				fprintf(fp, "%1.0f\t", matrixC[i][j]);
			}
			fprintf(fp, "\n");
		}
	}
	
	
	
	printf("\n");
	double en=omp_get_wtime();
	double elapsed = en-st;
	return elapsed;
}

void convert(TYPE** matrixA, TYPE** matrixB, int dimension){
	#pragma omp parallel for
	for(int i=0; i<dimension; i++){
		for(int j=0; j<dimension; j++){
			flatA[i * dimension + j] = matrixA[i][j];
			flatB[j * dimension + i] = matrixB[i][j];
		}
	}
}

void sequentialMultiplyTest(int dimension){
	FILE* fp;
	fp = fopen("SequentialMultiplyTest.txt", "a+");

	printf("----------------------------------\n");
	printf("Test : Sequential Multiply        \n\n");
	printf("Dimension : %d\n\n", dimension);
	
	fprintf(fp, "----------------------------------\n");
	fprintf(fp, "Test : Sequential Multiply        \n");
	fprintf(fp, "----------------------------------\n");
	fprintf(fp, "Dimension : %d\n", dimension);
	fprintf(fp, "..................................\n");

	double opmLatency;
	TYPE** matrixA = randomSquareMatrix(dimension);
	fprintf(fp, "matrixA \n");
	
	for(int i=0; i<dimension; i++){
			for(int j=0; j<dimension; j++){
				fprintf(fp, "%1.0f\t", matrixA[i][j]);
			}fprintf(fp, "\n");
	}
	fprintf(fp, "\n");
	
	
	TYPE** matrixB = randomSquareMatrix(dimension);
	fprintf(fp, "matrixB \n");
	for(int i=0; i<dimension; i++){
			for(int j=0; j<dimension; j++){
				fprintf(fp, "%1.0f\t", matrixB[i][j]);
			}fprintf(fp, "\n");
	}
	fprintf(fp, "\n");
	
	
	TYPE** matrixResult = zeroSquareMatrix(dimension);
	opmLatency = sequentialMultiply(matrixA, matrixB, matrixResult, dimension);
	
	fprintf(fp, "Result of A*B\n");
	for(int i=0; i<dimension; i++){
		for(int j=0; j<dimension; j++){
			fprintf(fp, "%1.0f\t", matrixResult[i][j]);
		}fprintf(fp, "\n");
	}
	fprintf(fp, "\n");
	
	
	printf("Time Taken: ");
	printf("%f\n", opmLatency);
	printf("----------------------------------\n\n");

	fprintf(fp, "Time Taken: ");
	fprintf(fp, "%f\n\n", opmLatency);

	fclose(fp);
	free(matrixA);
	free(matrixB);
}

void parallelMultiplyTest(int dimension){
	FILE* fp;
	fp = fopen("ParallelMultiplyTest.txt", "a+");

	printf("----------------------------------\n");
	printf("Test : Parallel Multiply          \n\n");
	printf("Dimension : %d\n\n", dimension);
	
	fprintf(fp, "----------------------------------\n");
	fprintf(fp, "Test : Parallel Multiply          \n");
	fprintf(fp, "----------------------------------\n");
	fprintf(fp, "Dimension : %d\n", dimension);
	fprintf(fp, "..................................\n");

	double opmLatency;
	TYPE** matrixA = randomSquareMatrix(dimension);
	fprintf(fp, "matrixA \n");
	
	for(int i=0; i<dimension; i++){
			for(int j=0; j<dimension; j++){
				fprintf(fp, "%1.0f\t", matrixA[i][j]);
			}fprintf(fp, "\n");
	}
	fprintf(fp, "\n");
	
	
	TYPE** matrixB = randomSquareMatrix(dimension);
	fprintf(fp, "matrixB \n");
	for(int i=0; i<dimension; i++){
			for(int j=0; j<dimension; j++){
				fprintf(fp, "%1.0f\t", matrixB[i][j]);
			}fprintf(fp, "\n");
	}
	fprintf(fp, "\n");
	
	
	TYPE** matrixResult = zeroSquareMatrix(dimension);
	opmLatency = parallelMultiply(matrixA, matrixB, matrixResult, dimension);
	
	fprintf(fp, "Result of A*B\n");
	for(int i=0; i<dimension; i++){
		for(int j=0; j<dimension; j++){
			fprintf(fp, "%1.0f\t", matrixResult[i][j]);
		}fprintf(fp, "\n");
	}
	fprintf(fp, "\n");
	
	
	printf("Time Taken: ");
	printf("%f\n", opmLatency);
	printf("----------------------------------\n\n");

	fprintf(fp, "Time Taken: ");
	fprintf(fp, "%f\n\n", opmLatency);

	fclose(fp);
	free(matrixA);
	free(matrixB);
	free(matrixResult);
}

void optimizedParallelMultiplyTest(int dimension){
	FILE* fp;
	fp = fopen("OptimizedParallelMultiplyTest.txt", "a+");

	printf("----------------------------------\n");
	printf("Test : Optimized Parallel Multiply\n\n");
	printf("Dimension : %d\n", dimension);
	
	fprintf(fp, "----------------------------------\n");
	fprintf(fp, "Test : Optimized Parallel Multiply\n");
	fprintf(fp, "----------------------------------\n");
	fprintf(fp, "Dimension : %d\n", dimension);
	fprintf(fp, "..................................\n");

	double opmLatency;
	TYPE** matrixA = randomSquareMatrix(dimension);
	fprintf(fp, "matrixA \n");
	
	for(int i=0; i<dimension; i++){
			for(int j=0; j<dimension; j++){
				fprintf(fp, "%1.0f\t", matrixA[i][j]);
			}fprintf(fp, "\n");
	}
	fprintf(fp, "\n");
	
	
	TYPE** matrixB = randomSquareMatrix(dimension);
	fprintf(fp, "matrixB \n");
	for(int i=0; i<dimension; i++){
			for(int j=0; j<dimension; j++){
				fprintf(fp, "%1.0f\t", matrixB[i][j]);
			}fprintf(fp, "\n");
	}
	fprintf(fp, "\n");
	
	
	TYPE** matrixResult = zeroSquareMatrix(dimension);
	opmLatency = optimizedParallelMultiply(matrixA, matrixB, matrixResult, dimension);
	free(matrixResult);
	
	fprintf(fp, "Result of A*B\n");
	for(int i=0; i<dimension; i++){
		for(int j=0; j<dimension; j++){
			fprintf(fp, "%1.0f\t", matrixResult[i][j]);
		}fprintf(fp, "\n");
	}
	fprintf(fp, "\n");
	
	
	printf("Time Taken: ");
	printf("%f\n", opmLatency);
	printf("----------------------------------\n\n\n");
	
	fprintf(fp, "Time Taken: ");
	fprintf(fp, "%f\n\n", opmLatency);

	fclose(fp);
	free(matrixA);
	free(matrixB);
}


TYPE** randomSquareMatrix(int dimension){

	TYPE** matrix = malloc(dimension * sizeof(TYPE*));

	for(int i=0; i<dimension; i++){
		matrix[i] = malloc(dimension * sizeof(TYPE));
	}

	#pragma omp parallel for
	for(int i=0; i<dimension; i++){
		for(int j=0; j<dimension; j++){
			matrix[i][j] = i+j;
		}
	}

	return matrix;
}


TYPE** zeroSquareMatrix(int dimension){

	TYPE** matrix = malloc(dimension * sizeof(TYPE*));

	for(int i=0; i<dimension; i++){
		matrix[i] = malloc(dimension * sizeof(TYPE));
	}

	for(int i=0; i<dimension; i++){
		for(int j=0; j<dimension; j++){
			matrix[i][j] = 0;
		}
	}

	return matrix;
}


void displaySquareMatrix(TYPE** matrix, int dimension){
	for(int i=0; i<dimension; i++){
		for(int j=0; j<dimension; j++){
			printf("%1.0f\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

