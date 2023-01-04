#include <mpi.h>
#include <stdio.h>
#include<string.h>

int main(int argc, char** argv) {
    char msg[20];
    int array[] = {11,12,13,14,15,16,17,18,19,20,21,22};
    int array2[8] = {79, 99, 1, 7};
    int rec[5];
    int myrank, tag=99;
   
   
    MPI_Init(&argc, &argv);
   
    MPI_Status status;
   
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
   
    if(myrank == 0) {
    strcpy(msg, "Hello There");
    MPI_Send(msg, 6, MPI_CHAR, 1, tag, MPI_COMM_WORLD);
   
    }
   
    if(myrank == 1)
    MPI_Recv(msg, 6, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);   // I
   
    printf("process[%d]:  %s\n", myrank,msg);



	MPI_Bcast(array2, 2, MPI_INT, 1, MPI_COMM_WORLD);   //II
    printf("process[%d]:  %d\n", myrank,*array2);
	MPI_Scatter(array, 3, MPI_INT, rec, 3, MPI_INT, 3, MPI_COMM_WORLD); // III
	MPI_Gather(array2, 1, MPI_INT,rec, 1, MPI_INT, 2, MPI_COMM_WORLD); //IV
	printf("process[%d]:  %d\n", myrank,*array2);
	MPI_Allgather(rec, 2, MPI_INT, array2, 2, MPI_INT, MPI_COMM_WORLD);  // V

	printf("process[%d]:  %d\n", myrank,*array2);

	MPI_Finalize();

}
