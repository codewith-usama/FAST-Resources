#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"
#include <time.h>
#include <sys/time.h>

void mpi_func(int dimension, int task_id, int num_tasks, MPI_Status status);
             
#define MASTER 0 
#define FROM_MASTER 1
#define FROM_WORKER 2


int main(int argc, char *argv[]){

	int t_id, tasks;


	MPI_Status s;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &t_id);
	MPI_Comm_size(MPI_COMM_WORLD, &tasks);
	
	int dimension = 500;

	mpi_func(dimension, t_id, tasks, s);

	MPI_Finalize();

	return 0;	
}
void mpi_func(int dimension, int task_id, int num_tasks, MPI_Status status)
{
	FILE* fp;
	fp = fopen("Parallel_MPI_Multiply.txt", "a+");
	

	int num_workers, source, dest, msg_type, rows, averow, extra, offset, i, j, k, rc, mtype;
	double	MATRIX_A[dimension][dimension], MATRIX_B[dimension][dimension], MATRIX_RES[dimension][dimension];
	
	if(num_tasks < 2)
	{
		printf("This application is meant to be run with 2 or more processes.\n");
		MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
	}

	num_workers = num_tasks-1;

	//---------------------------------Master Process--------------------------------------------------

	if (task_id == MASTER) // master is process 0
	{
		printf("\nMPI MATRIX MULTIPLICATION HAS STARTED WITH %d PROCESSES\n", num_tasks);
		printf("\nInitializing Arrays\n");
		
		srand ( time(NULL) );
		for (i=0; i<dimension; i++)
		{
			for (j=0; j<dimension; j++)
			{
				MATRIX_A[i][j]= rand()%10;
			}
		}
		
		for (i=0; i<dimension; i++)
		{
			for (j=0; j<dimension; j++)
			{
				MATRIX_B[i][j]= rand()%10;
			}
		}
		
		double start = MPI_Wtime();
		
		// Send matrix data to the worker tasks
		averow = dimension/num_workers;
		extra = dimension % num_workers;
		offset = 0;
		mtype = FROM_MASTER; //=1
		for (dest=1; dest<=num_workers; dest++)
		{
			rows = (dest <= extra) ? averow+1 : averow;   	
			printf("Sending %d rows to [Process %d] offset = %d\n", rows, dest, offset);
			//MPI_Send(void* data, int count, MPI_Datatype datatype, destination process id, int tag,  MPI_Comm communicator)
			MPI_Send(&offset, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
			MPI_Send(&rows, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
			MPI_Send(&MATRIX_A[offset][0], rows*dimension, MPI_DOUBLE, dest, mtype, MPI_COMM_WORLD);
			MPI_Send(&MATRIX_B, dimension*dimension, MPI_DOUBLE, dest, mtype, MPI_COMM_WORLD);
			offset = offset + rows;
		}
		
		printf("\n");

		// Receive results from worker tasks
		mtype = FROM_WORKER; //=2
		for (i=1; i<=num_workers; i++)
		{
			source = i;

			//MPI_Recv(void* data, int count, MPI_Datatype datatype, source process id, int tag, MPI_Comm communicator, 			        // MPI_Status* status)
			MPI_Recv(&offset, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
			MPI_Recv(&rows, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
			MPI_Recv(&MATRIX_RES[offset][0], rows*dimension, MPI_DOUBLE, source, mtype, MPI_COMM_WORLD, &status);
			
			printf("Received results from [Process %d]\n", source);
		}
		
		// Print results
		
		if (dimension==100)
		{	
			FILE* file;
			file = fopen("MPI_Result.txt", "a+");

			for (i=0; i<dimension; i++)
			{ 
				for (j=0; j<dimension; j++)
				{
					fprintf(file, "%6.2f   ", MATRIX_RES[i][j]);
				}
			}

			fclose(file);
		}

		double finish = MPI_Wtime();
		printf("\nTime taken: %f seconds.\n", finish - start);

		fprintf(fp, "----------------------------------\n");
		fprintf(fp, "Parallel MPI Multiply        \n");
		fprintf(fp, "----------------------------------\n");
		fprintf(fp, "Dimension : %d\n", dimension);
		fprintf(fp, "Time : %f seconds\n", finish - start);

		fclose(fp);
		
		
	}
	
	//-----------------------Worker Processes--------------------------

	if (task_id > MASTER)
   	{
		mtype = FROM_MASTER; //=1
		
		//MPI_Recv(void* data, int count, MPI_Datatype datatype, int source process id, int tag, MPI_Comm communicator, MPI_Status* 			status)
		MPI_Recv(&offset, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD, &status);
		MPI_Recv(&rows, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD, &status);
		MPI_Recv(&MATRIX_A, rows*dimension, MPI_DOUBLE, MASTER, mtype, MPI_COMM_WORLD, &status);
		MPI_Recv(&MATRIX_B, dimension*dimension, MPI_DOUBLE, MASTER, mtype, MPI_COMM_WORLD, &status);
         
		 for (k=0; k<dimension; k++)
		 {
		 	for (i=0; i<rows; i++)
		 	{
		 		MATRIX_RES[i][k] = 0.0;
		 		for (j=0; j<dimension; j++)
		 		{
		 			MATRIX_RES[i][k] = MATRIX_RES[i][k] + MATRIX_A[i][j] * MATRIX_B[j][k];
				}
			}
		}
         
		mtype = FROM_WORKER; //=2
		MPI_Send(&offset, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD);
		MPI_Send(&rows, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD);
		MPI_Send(&MATRIX_RES, rows*dimension, MPI_DOUBLE, MASTER, mtype, MPI_COMM_WORLD);
		// fro np = 4, rows=166/167...number of data iterms to send is rows*col(dimension)
   	}
   	
}

