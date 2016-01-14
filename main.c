#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "gaussseidel.h"
#include "jacobi.h"

int main(int argc, char *argv[]) {
	printf("Usage: ./poisson 5 jacobi\n");

	int real_size = 64;

	// Looks if N is defined as argument.
	if (argc > 1) {
		printf("The argument supplied for N is: %s\n", argv[1]);
		real_size = atoi(argv[1]);
	}

	int N = real_size+2;
	double **A = dmalloc_2d(N);
	double **b = dmalloc_2d(N);
	set_A(A,N);
	set_B(b,N);

	// Choose a method
	double **x;
	if (argc > 2) {
		printf("The argument supplied for the method is: %s\n", argv[2]);
		if (strcmp(argv[2],"jacobi") != 0) {
			printf("executing jacobi sequential...\n");
			x = jacobi(A,b,N, 1000);
		} else if (strcmp(argv[2],"gausseidel") != 0) {
			printf("executing gaussseidel sequential...\n");
			x = gaussseidel(A,b,N, 1000);
		} else {
			printf("Unknown argument %s will execute gaussseidel sequential\n", argv[2]);
			x = gaussseidel(A,b,N, 1000);
		}
	} else {
		printf("No argument suplied will use gaussseidel sequential with N: %i\n", real_size);
		x = gaussseidel(A,b,N, 1000);
	}

	// save result
	writeArray2file(x,N);

	return 0;
}
