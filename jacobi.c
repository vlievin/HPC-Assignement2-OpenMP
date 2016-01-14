#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "jacobi.h"
#include "utils.h"

double** jacobi( double **A, double** b, int N, int nb_iter, double threshold)
{

	double ** x = dmalloc_2d(N);
	double ** x_tmp = dmalloc_2d(N);
	set_x0(x, N);
	set_x0(x_tmp, N);
	int i, j ,k;
	k = 0;
//	double d = INFINITY;
	double d = 10000000000;
	double delta = 2.0 / ((double)(N-3));
	while ( d > threshold && k < nb_iter )
	{
		for (i = 1; i < N-1; i++)
		{
			for (j = 1; j < N-1; j++)
			{
				x_tmp[i][j] = (x[i-1][j] + x[i+1][j] + x[i][j-1] + x[i][j+1] + delta * delta * b[i][j])/4.0;
			}
		}
		d = dist( x , x_tmp , N );
		x = x_tmp;
		k++;
	}

	printf("jacobi - k is: %i\n", k);

	//free_A(x_tmp); // --> seg fault
	return x;
}

