#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "gaussseidel.h"
#include "jacobi.h"

int main()
{
	int real_size = 100;
	int N = real_size * real_size;
	double ** A = dmalloc_2d(N);
	double * b = dmalloc_1d(N);
	double * x0 = dmalloc_1d(N);
	double * x = dmalloc_1d(N);
	printf("hehe\n");
	set_A(A,N);
	set_B(b,N);
	set_B(x0,N);

	jacobi2(A,b,x, x0,N, 10);

	printf("##########################\n");
	displayVect(x, N);

	return 0;

}
