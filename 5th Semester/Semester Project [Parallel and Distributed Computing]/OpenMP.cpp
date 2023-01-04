#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>
#include <omp.h>

typedef double TYPE;
#define DIM 500
#define MAX_DIM DIM*DIM
#define SDIM 100
#define IDIM 100


TYPE** random_square_matrix(int dimension);
TYPE** zero_square_matrix(int dimension);
void display_square_matrix(TYPE** matrix, int dimension);
void convert_to_1DArray(TYPE** MATRIX_A, TYPE** MATRIX_B, int dimension);


double sequentialMultiply(TYPE** MATRIX_A, TYPE** MATRIX_B, TYPE** MATRIX_RES, int dimension);
double parallelMultiply(TYPE** MATRIX_A, TYPE** MATRIX_B, TYPE** MATRIX_RES, int dimension);
double optimizedParallelMultiply(TYPE** MATRIX_A, TYPE** MATRIX_B, TYPE** MATRIX_RES, int dimension);

void sequentialMultiplyTime(int dimension);
void ParallelMultiplyTime(int dimension);
void optimizedParallelMultiplyTime(int dimension);



TYPE containerA[MAX_DIM];
TYPE containerB[MAX_DIM];

int main(){
	
	FILE* fp;
	fp = fopen("sequentialMultiplyTime.txt", "w+");
	fclose(fp);

	fp = fopen("ParallelMultiplyTime.txt", "w+");
	fclose(fp);

	fp = fopen("OptimizedParallelMultiplyTime.txt", "w+");
	fclose(fp);
	
	for(int dimension=SDIM; dimension<=DIM; dimension+=IDIM){
		optimizedParallelMultiplyTime(dimension);
	}

	for(int dimension=SDIM; dimension<=DIM; dimension+=IDIM){
		ParallelMultiplyTime(dimension);
	}

	for(int dimension=SDIM; dimension<=DIM; dimension+=IDIM){
		sequentialMultiplyTime(dimension);
	}

	return 0;
}

TYPE** random_square_matrix(int dimension){
	
	
	TYPE** matrix = malloc(dimension * sizeof(TYPE*));

	for(int i=0; i<dimension; i++){
		matrix[i] = malloc(dimension * sizeof(TYPE));
	}

    	srand ( time(NULL) );
	#pragma omp parallel for
	for(int i=0; i<dimension; i++){
		for(int j=0; j<dimension; j++){
			matrix[i][j] = rand()%10;
		}
	}

	return matrix;
}

TYPE** zero_square_matrix(int dimension){

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

void display_square_matrix(TYPE** matrix, int dimension)
{
	
	for(int i=0; i<dimension; i++){
		for(int j=0; j<dimension; j++){
			printf("%1.0f\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

void display_square_matrixfile(TYPE** matrix, int dimension){
	FILE* fp;
	fp = fopen("Parallel_ResultMatrix.txt", "w+");
	for(int i=0; i<dimension; i++){
		for(int j=0; j<dimension; j++){
			fprintf(fp,"%1.0f\t", matrix[i][j]);
		}
		fprintf(fp,"\n");
	}
	fprintf(fp,"\n");
	fclose(fp);
}


double sequentialMultiply(TYPE** MATRIX_A, TYPE** MATRIX_B, TYPE** MATRIX_RES, int dimension){

	double start=omp_get_wtime();
	for(int i=0; i<dimension; i++){
		for(int j=0; j<dimension; j++){
			for(int k=0; k<dimension; k++){
				MATRIX_RES[i][j] += MATRIX_A[i][k] * MATRIX_B[k][j];
			}
		}
	}

	double end=omp_get_wtime();
	double elapsed = end-start;

	return elapsed;
}

double parallelMultiply(TYPE** MATRIX_A, TYPE** MATRIX_B, TYPE** MATRIX_RES, int dimension){

	int i, j, k;	

	double start=omp_get_wtime();

	#pragma omp parallel shared(MATRIX_RES) private(i, j, k) num_threads(8)
	{
		double st=omp_get_wtime();
		#pragma omp for
		for(int i=0; i<dimension; i++){
			for(int j=0; j<dimension; j++){
				for(int k=0; k<dimension; k++){
					MATRIX_RES[i][j] += MATRIX_A[i][k] * MATRIX_B[k][j];
				}
			}
		}
		double en=omp_get_wtime();
		printf("\nTime taken = %f seconds by [thread %d] \n", en-st, omp_get_thread_num());
		
		display_square_matrixfile(MATRIX_RES, dimension);
	
	}

	double end=omp_get_wtime();
	double elapsed = end-start;	

	return elapsed;
}

double optimizedParallelMultiply(TYPE** MATRIX_A, TYPE** MATRIX_B, TYPE** MATRIX_RES, int dimension){

	int i, j, k, iOff, jOff;
	TYPE total;

	double start=omp_get_wtime();

	convert_to_1DArray(MATRIX_A, MATRIX_B, dimension);
	
	#pragma omp parallel shared(MATRIX_RES) private(i, j, k, iOff, jOff, total) num_threads(8)
	{
		#pragma omp for 
		for(i=0; i<dimension; i++){
			iOff = i * dimension;
			for(j=0; j<dimension; j++){
				jOff = j * dimension;
				total = 0;
				for(k=0; k<dimension; k++){
					total += containerA[iOff + k] * containerB[jOff + k];
				}
				MATRIX_RES[i][j] = total;
			}
		}
		//printf("\nFrom thread ID %d= ", omp_get_thread_num());
		//printf("\n");
		//display_square_matrix(MATRIX_RES, dimension);
		FILE* fp;
		fp = fopen("OptimizedParallelMultiplyTime.txt", "a+");
		//fprintf(fp, "\n from thread ID %d= ",omp_get_thread_num());
		//fprintf(fp, "\n");
		//display_square_matrixfile(MATRIX_RES, dimension);
	    fclose(fp);
			
	}

	double end=omp_get_wtime();
	double elapsed = end-start;

	return elapsed;
}

void convert_to_1DArray(TYPE** MATRIX_A, TYPE** MATRIX_B, int dimension){
	
	#pragma omp parallel for
	for(int i=0; i<dimension; i++){
		for(int j=0; j<dimension; j++){
			containerA[i * dimension + j] = MATRIX_A[i][j];
			containerB[j * dimension + i] = MATRIX_B[i][j];
		}
	}
}

void sequentialMultiplyTime(int dimension){
	FILE* fp;
	fp = fopen("sequentialMultiplyTime.txt", "a+");

	printf("----------------------------------\n");
	printf("Test : Sequential Multiply        \n");
	printf("----------------------------------\n");
	printf("Dimension : %d\n", dimension);
	
	fprintf(fp, "----------------------------------\n");
	fprintf(fp, "Test : Sequential Multiply        \n");
	fprintf(fp, "----------------------------------\n");
	fprintf(fp, "Dimension : %d\n", dimension);

	double opmLatency;
	TYPE** MATRIX_A = random_square_matrix(dimension);
	TYPE** MATRIX_B = random_square_matrix(dimension);
	

	TYPE** matrixResult = zero_square_matrix(dimension);
	opmLatency = sequentialMultiply(MATRIX_A, MATRIX_B, matrixResult, dimension);
	free(matrixResult);

	printf("Time Taken: %f seconds\n\n", opmLatency);
	fprintf(fp, "Time Taken: %f seconds\n\n", opmLatency);

	fclose(fp);
	free(MATRIX_A);
	free(MATRIX_B);
}

void ParallelMultiplyTime(int dimension){
	FILE* fp;
	fp = fopen("ParallelMultiplyTime.txt", "a+");

	printf("----------------------------------\n");
	printf("Test : Parallel Multiply          \n");
	printf("----------------------------------\n");
	printf("Dimension : %d\n", dimension);
	
	fprintf(fp, "----------------------------------\n");
	fprintf(fp, "Test : Parallel Multiply          \n");
	fprintf(fp, "----------------------------------\n");
	fprintf(fp, "Dimension : %d\n", dimension);

	double opmLatency;
	TYPE** MATRIX_A = random_square_matrix(dimension);
	TYPE** MATRIX_B = random_square_matrix(dimension);

	TYPE** matrixResult = zero_square_matrix(dimension);
	opmLatency = parallelMultiply(MATRIX_A, MATRIX_B, matrixResult, dimension);
	free(matrixResult);

	printf("\nTime Taken: %f seconds\n\n", opmLatency);

	fprintf(fp, "Time Taken: %f seconds\n\n", opmLatency);

	fclose(fp);
	free(MATRIX_A);
	free(MATRIX_B);
}
void optimizedParallelMultiplyTime(int dimension){
	FILE* fp;
	fp = fopen("OptimizedParallelMultiplyTime.txt", "a+");

	printf("----------------------------------\n");
	printf("Test : Optimized Parallel Multiply\n");
	printf("----------------------------------\n");
	printf("Dimension : %d\n", dimension);
	
	fprintf(fp, "----------------------------------\n");
	fprintf(fp, "Test : Optimized Parallel Multiply\n");
	fprintf(fp, "----------------------------------\n");
	fprintf(fp, "Dimension : %d\n", dimension);

	double opmLatency;
	TYPE** MATRIX_A = random_square_matrix(dimension);
	//printf("MATRIX_A \n");
	//display_square_matrix(MATRIX_A, dimension);
	TYPE** MATRIX_B = random_square_matrix(dimension);
	//printf("MATRIX_B \n");
	//display_square_matrix(MATRIX_B, dimension);
	
	
	TYPE** matrixResult = zero_square_matrix(dimension);
	opmLatency = optimizedParallelMultiply(MATRIX_A, MATRIX_B, matrixResult, dimension);
	free(matrixResult);

	printf("Time taken: %f seconds\n\n", opmLatency);

	fprintf(fp, "Time taken: %f seconds\n\n", opmLatency);

	fclose(fp);
	free(MATRIX_A);
	free(MATRIX_B);
}

