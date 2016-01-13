#include <stdio.h>
#include <stdlib.h>
#include "gaussseidel.h"
#include "utils.h"

double** gaussseidel( double **A, double** b, int N, int nb_iter)
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
				x_tmp[i][j] = (x_tmp[i-1][j] + x[i+1][j] + x_tmp[i][j-1] + x[i][j+1] + delta * delta * b[i][j])/4.0;
			}
		}
		x = x_tmp;
	}
	
	//free_A(x_tmp); // --> seg fault
	
	return x;

}

