#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "gaussseidel.h"
#include "jacobi.h"

int main()
{
	int real_size = 64;
	real_size +=2;
	int N = real_size;
	double ** A = dmalloc_2d(N);
	double ** b = dmalloc_2d(N);
	//double * x = dmalloc_1d(N);
	set_A(A,N);
	set_B(b,N);
	
	double**x = gaussseidel(A,b,N, 1000);

	//writeArray2file(b,N);
	writeArray2file(x,N);

	return 0;

}
