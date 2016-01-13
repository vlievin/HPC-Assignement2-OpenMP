#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"


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

void set_A(double** A, int N){

	/*int i,j;
	for(i=0; i<N; i++){    
	        for(j=0; j<N; j++){  
               		scanf("%lf",&A[i][j]);
        	}
        	printf("\n");
    	}*/
	int i;
	A[0][0] = -4;
	for ( i = 1; i < N; i++)
	{
		A[i][i] = -4;
		A[i-1][i] = 1;
		A[i][i-1] = 1;
	}	
}

void displayArray(double **A, int N)
{
	int i,j;
	for (j = 0; j < N; j++)
	{
		for (i=0; i<N;i++)
		{
			printf( "%f" , A[i][j]  );
			printf(" ");
		}
		printf("\n");
	}

}

void set_B (double*B, int N){

	/*int i;
	for(i=0; i<N; i++){
		scanf("%lf",&B[i]);
	}*/
	int i;
	for(i=0; i<N; i++){
		B[i] = 0;
	}

	double v = 200; 
	double n = sqrt( (double)N );
	int j;
	i = 0;
	for (i = 0 ; i < n; i++)
	{
		double y = -1.0 + 2.0 * (float)i/n;
		for (j = 0; j < n ; j++)
		{
			double x = -1.0 + 2.0 * (float)j/n;
			if (x >= 0 && x <= 1.0/3.0 && y >= -2.0/3.0 && y <= -1.0/3.0)
				B[i + (int)n * j] = 200.0;
			else
				B[i + (int)n * j] = 0.0;
				

		}
	}
}

void displayVect(double *B, int N)
{
	int i;
	for(i=0; i<N; i++){
		printf("%f  ", B[i]);
	}
}


void free_A(double **A){
    
    free(A[0]);
    free(A);
}

void free_B(double *B){

	free(B);
}
