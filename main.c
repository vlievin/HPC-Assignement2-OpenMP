#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "gaussseidel.h"
//#include "jacobi.h"

int main()
{
	int real_size = 2;
	int N = real_size * real_size;
	double ** A = dmalloc_2d(N);
	double * b = dmalloc_1d(N);
	double * x0 = dmalloc_1d(N);
	printf("\n");
	set_A(A,N);
	set_B(b,N);
	displayArray(A, N);
	printf("\n\n");
	displayVect(b,N);
	//gaussseidel(A,b,x0,N);

	return 0;

}
