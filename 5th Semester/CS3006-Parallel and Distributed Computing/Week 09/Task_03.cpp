#include <mpi.h>
#include <stdio.h>


int main(int argc, char *argv[]) {

	int npes, myrank;

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &npes);

	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

	if (myrank==1)
		printf("From process %d out of %d, Hello World!\n", myrank, npes);

	else if(myrank==0)
		printf("Hello Usama %d out of %d, kashif\n", myrank, npes);

	MPI_Finalize();
	
	
	return 0;
}
