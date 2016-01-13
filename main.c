#include <stdio.h>
#include <stdlib.h>
#include "gaussseidel.h"
#include "jacobi.h"

double ** dmalloc_2d(int N) {

	if (N <= 0 ) return NULL;
	double **A = malloc(N * sizeof(double *));
	if (A == NULL) return NULL;
	A[0] = malloc(N*N*sizeof(double));
	if (A[0] == NULL) {
		free(A);
	return NULL;
	}
	int i;
	for (i = 1; i < N; i++)
		A[i] = A[0] + i * N;
	return A;
}

double * dmalloc_1d(int N){

	double *B;
	B = (double *) malloc(N*sizeof(double));

	return B;
}

double ** Get_A(int N){

	double ** A = dmalloc_2d(N);

	int i,j;
	for(i=0; i<N; i++){    
	        for(j=0; j<N; j++){  
               		scanf("%lf",&A[i][j]);
        	}
        	printf("\n");
    	}
	return A;	
}

double * Get_B (int N){

	double * B = dmalloc_1d(N);
	int i;
	for(i=0; i<N; i++){
		scanf("%lf",&B[i]);
	}
	return B;
}

void free_A(double **A){
    
    free(A[0]);
    free(A);
}

void free_B(double *B){

	free(B);
}




int main()
{
	printf("hello world");

	return 0;

}
