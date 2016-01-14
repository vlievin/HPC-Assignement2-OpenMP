#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gaussseidel.h"
#include "utils.h"

double** gaussseidel( double **A, double** b, int N, int nb_iter, double threshold)
{

	double ** x = dmalloc_2d(N);
	double ** x_tmp = dmalloc_2d(N);
        // used for update
        double ** tmp = 0;
	set_x0(x,N);
	set_x0(x_tmp, N);
	int i, j, k;
	k = 0;
       	double d = INFINITY;
	double delta = 2.0 / ((double)(N-3));
	double tmp_var = 0.0;
        while ( d > threshold && k < nb_iter )
	{
		d = 0.0;
		for (i = 1; i < N-1; i++)
		{
			for (j = 1; j < N-1; j++)
			{
				tmp_var = x_tmp[i][j];
				x_tmp[i][j] = (x_tmp[i-1][j] + x[i+1][j] + x_tmp[i][j-1] + x[i][j+1] + delta * delta * b[i][j])/4.0;
				d += x_tmp[i][j]*x_tmp[i][j] - tmp_var*tmp_var;
			}
		}
               	tmp = x;
                x = x_tmp;
                x_tmp = tmp;
                k++;
	}
        printf("gauss-seidel - k is: %i\n", k);
        free_A(x_tmp);
        return x;
}

