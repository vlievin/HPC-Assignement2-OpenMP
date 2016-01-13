#include "gaussseidel.h"
#include "utils.h"
 
void split(double** A, double** L, double** U, int N)
{
	int i,j;
	for (i = 0; i<N; i++)
	{
		for (j=0;j<N;j++)
		{
			if ( j > i)
			{
				U[i][j] = A[i][j];
				L[i][j] = 0.0;
			}
			else
			{
				U[i][j] = 0.0;
				L[i][j] = A[i][j];
			}
		}
	}

}


double* gaussseidel( double **A, double* b, double* x0, int N)
{
	double * X = dmalloc_1d(N);
	double ** L = dmalloc_2d(N);
	double ** U = dmalloc_2d(N);
	
	split(A,L,U,N);
	displayArray(L,N);
	printf("------------------------------\n");
	displayArray(U,N);

	return X;

}
