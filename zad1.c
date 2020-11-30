#include "mpi.h"
#include <stdio.h>
#include <math.h>

/* module load gcc */
/* module load mpich/ge/gcc/64/3.1 */
/* Compile me with 'mpicc -o cpi-parallel cpi-parallel.c' */


double f( double );
double f( double a )
{
    return (4.0 / (1.0 + a*a));
}

int main( int argc, char *argv[])
{
    int done = 0, n, myid, numprocs, i;
    double PI_real = 3.141592653589793238462643;
    double mypi, pi, h, sum, x;
    double startwtime = 0.0, endwtime;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);

    n = 0;
    while (!done)
    {
	    if (n==0) n=1024*numprocs; else n=0;

	    startwtime = MPI_Wtime();
        MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
        if (n == 0) done = 1;
        else
        {
            sum = 0.0;
        	for(i = myid ; i < n; i += numprocs) 
			{ 
                sum += pow((-1),i)*(4.0 / (2*i+1)); 
            } 
            mypi = sum;

            MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

            if (myid == 0)
	    	{
                printf("Wartosc PI= %.16f, Blad= %.16f\n",pi, fabs(pi - PI_real));
				endwtime = MPI_Wtime();
				printf("Czas programu: = %f\n",
		    	endwtime-startwtime);
	    	}
        }
    }
    MPI_Finalize();
    return 0;
}
