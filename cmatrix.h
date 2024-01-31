#include <stdlib.h>

#ifndef cmatrix
#define cmatrix
typedef double cmatrix_elem;
typedef struct {
	size_t rows;
	size_t cols;
	cmatrix_elem *data;
} cmatrix;
#endif

cmatrix *cmatrix_new(size_t rows, size_t cols);
void cmatrix_free(cmatrix *m);
void cmatrix_print(cmatrix *m);
void cmatrix_set(cmatrix *m, size_t row, size_t col, cmatrix_elem val);
cmatrix_elem cmatrix_get(cmatrix *m, size_t row, size_t col);
cmatrix *cmatrix_add(cmatrix *m1, cmatrix *m2);
cmatrix *cmatrix_sub(cmatrix *m1, cmatrix *m2);
cmatrix *cmatrix_mul(cmatrix *m1, cmatrix *m2);
cmatrix *cmatrix_mul_scalar(cmatrix *m, cmatrix_elem scalar);
cmatrix *cmatrix_transpose(cmatrix *m);
cmatrix *cmatrix_dot(cmatrix *m1, cmatrix *m2);
