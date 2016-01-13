#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "gaussseidel.h"
//#include "jacobi.h"

int main()
{
	int real_size = 5;
	int N = real_size * real_size;
	double ** A = dmalloc_2d(N);
	double * B = dmalloc_1d(N);
	printf("\n");
	set_A(A,N);
	set_B(B,N);
	displayArray(A, N);
	printf("\n\n");
	displayVect(B,N);

	return 0;

}
