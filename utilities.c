#include "utilities.h"
/* 
* Dealing with common vector operations 
*
* ==================== WARNING ====================
* 	The caller should have thought about the memory 
*	   allocation, these functions assumes that 
*	   everything is OK. If not used with care, 
*		prohibted reads/writes might occur.
* =================================================
*
*/

// used on contigous vectors
void 	vectors_add(double* A, double* B, int L)
{
	int l = 0;
	while ( l < L ) {
		A[l] += B[l];
		++l;
	}
}
void 	vectors_substract(double* A, double* B, int L)
{
	int l = 0;
	while ( l < L ) {
		A[l] -= B[l];
		++l;
	}
}

void 	vectors_multiply(double* A, double* B, int L)
{
	int l = 0;
	while ( l < L ) {
		A[l] *= B[l];
		++l;
	}
}
void 	vectors_mutliply_scalar(double* A, double b, int L)
{
	int l = 0;
	while ( l < L ) {
		A[l] *= b;
		++l;
	}
}	

int 	init_random_matrix(double*** A, int R, int C)
{
	int r = 0, c = 0;

	*A = calloc(R, sizeof(double*));

	if ( *A == NULL )
		return -1;

	while ( r < R ) {
		(*A)[r] = calloc(C, sizeof(double));
		if ( (*A)[r] == NULL )
			return -2;
		++r;
	}

	r = 0, c = 0;

	while ( r < R ){
		c = 0;
		while ( c < C ){
			(*A)[r][c] =  ((( (double) rand() ) / RAND_MAX) - 0.5 ) / sqrt( R / 2.0 ); 
			++c;
		}
		++r;
	}

	return 0;
}

double** 	get_random_matrix(int R, int C)
{
	int r = 0, c = 0;
	double ** p;
	p = calloc(R, sizeof(double*));

	if ( p == NULL )
		exit(-1);

	while ( r < R ) {
		p[r] = calloc(C, sizeof(double));
		if ( p[r] == NULL )
			exit(-1);
		++r;
	}

	r = 0, c = 0;

	while ( r < R ){
		c = 0;
		while ( c < C ){
			p[r][c] =  ((( (double) rand() ) / RAND_MAX) - 0.5 ) / sqrt( R / 2.0 ); 
			++c;
		}
		++r;
	}

	return p;
}

double** 	get_zero_matrix(int R, int C)
{
	int r = 0, c = 0;
	double ** p;
	p = calloc(R, sizeof(double*));

	if ( p == NULL )
		exit(-1);

	while ( r < R ) {
		p[r] = calloc(C, sizeof(double));
		if ( p[r] == NULL )
			exit(-1);
		++r;
	}

	r = 0, c = 0;

	while ( r < R ){
		c = 0;
		while ( c < C ){
			p[r][c] =  0.0;
			++c;
		}
		++r;
	}

	return p;
}

int 	init_zero_matrix(double*** A, int R, int C)
{
	int r = 0, c = 0;

	*A = calloc(R, sizeof(double*));

	if ( *A == NULL )
		return -1;

	while ( r < R ) {
		(*A)[r] = calloc(C, sizeof(double));
		if ( (*A)[r] == NULL )
			return -2;
		++r;
	}

	r = 0, c = 0;

	while ( r < R ){
		c = 0;
		while ( c < C ){
			(*A)[r][c] = 0.0;
			++c;
		}
		++r;
	}

	return 0;
}

int 	free_matrix(double** A, int R)
{
	int r = 0;
	while ( r < R ) {
		free(A[r]);
		++r;	
	}
	free(A);
	return 0;
}

int 	init_zero_vector(double** V, int L) 
{
	int l = 0;
	*V = calloc(L, sizeof(double));
	if ( *V == NULL )
		return -1;

	while ( l < L ){
		(*V)[l] = 0.0;
		++l;
	}
 
	return 0;
}

double* 	get_zero_vector(int L) 
{
	int l = 0;
	double *p;
	p = calloc(L, sizeof(double));
	if ( p == NULL )
		exit(0);

	while ( l < L ){
		p[l] = 0.0;
		++l;
	}

	return p;
}

int 	free_vector(double** V)
{
	free(*V);
	*V = NULL;
	return 0;
}

void 	copy_vector(double* A, double* B, int L)
{
	int l = 0;

	while ( l < L ){
		A[l] = B[l];
		++l;
	}
}

void 	matrix_add(double** A, double** B, int R, int C)
{
	int r = 0, c = 0;

	while ( r < R ) {
		c = 0;
		while ( c < C ) {
			A[r][c] += B[r][c];
			++c;
		}
		++r;
	}
}

void 	vector_set_to_zero(double* V, int L )
{
	int l = 0;
	while ( l < L )
		V[l++] = 0.0;
}


void 	matrix_set_to_zero(double** A, int R, int C)
{
	int r = 0, c = 0;

	while ( r < R ) {
		c = 0;
		while ( c < C ) {
			A[r][c] = 0.0;
			++c;
		}
		++r;
	}
}

void 	matrix_substract(double** A, double** B, int R, int C)
{
	int r = 0, c = 0;

	while ( r < R ) {
		c = 0;
		while ( c < C ) {
			A[r][c] -= B[r][c];
			++c;
		}
		++r;
	}
}

void 	matrix_scalar_multiply(double** A, double b, int R, int C)
{
	int r = 0, c = 0;

	while ( r < R ) {
		c = 0;
		while ( c < C ) {
			A[r][c] *= b;
			++c;
		}
		++r;
	}
}
void 	matrix_clip(double** A, double limit, int R, int C)
{
	int r = 0, c = 0;

	while ( r < R ) {
		c = 0;
		while ( c < C ) {
			if ( A[r][c] > limit )
				A[r][c] = limit;
			else if ( A[r][c] < -limit )
				A[r][C] = -limit;
			++c;
		}
		++r;
	}
}

void 	vectors_clip(double* V, double limit, int L)
{
	int l = 0;
	while ( l < L ){
		if ( V[l] > limit )
			V[l] = limit;
		else if ( V[l] < -limit )
			V[l] = -limit;
		++l;
	}
}

