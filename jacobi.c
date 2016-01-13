#include <stdio.h>
#include <stdlib.h>
#include "jacobi.h"
#include "utils.h"

/*double* jacobi( double **A, double* b, double* x0, int N, int nb_iter)
{	
	double * x = dmalloc_1d(N);
	double * x_tmp = dmalloc_1d(N);
	x = x0;
	int i, j ,k;
	for (k = 0; k < nb_iter ; k++)
	{
		for (i = 0; i < N; i++)
		{
			double s = 0;
			for (j = 0; j < N; j++)
			{
				if ( j != i )
				{
					s = s + A[i][j] * x[j];
				}
			}
			x_tmp[i] = ( b[i] - s ) / A[i][i] ;
		}
		x = x_tmp;
	}
	
	free_B(x_tmp);
	return x;

}*/

double** jacobi( double **A, double** b, int N, int nb_iter)
{	
	double ** x = dmalloc_2d(N);
	double ** x_tmp = dmalloc_2d(N);	
	set_x0(x,N);
	set_x0(x_tmp, N);
	int i, j ,k;
	double delta = 2.0 / ((double)(N-3));
	for (k = 0; k < nb_iter ; k++)
	{
		for (i = 1; i < N-1; i++)
		{	
			for (j = 1; j < N-1; j++)
			{
				x_tmp[i][j] = (x[i-1][j] + x[i+1][j] + x[i][j-1] + x[i][j+1] + delta * delta * b[i][j])/4.0;
			}
		}
		x = x_tmp;
	}
	
	//free_A(x_tmp); // --> seg fault
	
	return x;

}

