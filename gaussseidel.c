#include "gaussseidel.h"
#include "utils.h"
 
/*void split(double** A, double** L, double** U, int N)
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
}*/


double* gaussseidel( double **A, double* b, double* x0, int N, int nb_iter)
{
	double * x = dmalloc_1d(N);
	double * x_tmp = dmalloc_1d(N);
	double ** L = dmalloc_2d(N);
	double ** U = dmalloc_2d(N);
	
	//split(A,L,U,N);	

	x = x0;
	int i, j ,k;
	for (k = 0; k < nb_iter ; k++)
	{
		for (i = 0; i < N; i++)
		{
			double sl = 0;
			double sr = 0;
			for (j = 0; j < N; j++)
			{
				if ( j < i )
				{
					sl += A[i][j] * x_tmp[j];
				}
				else if ( j > i )
				{
					sr += A[i][j] * x[j];
				}
			}

			x_tmp[i] = 1.0 / A[i][i] * ( b[i] - sl - sr );
		}

		x = x_tmp;
	}

	return x;

}
