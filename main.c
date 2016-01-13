#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "gaussseidel.h"
//#include "jacobi.h"

int main()
{
	int N = 9;
	double ** A = dmalloc_2d(N);
	double * B = dmalloc_1d(N);
	printf("hello world");
	set_A(A,N);
	set_B(B,N);
	displayArray(A, N);

	return 0;

}
