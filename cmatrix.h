/* Copyright (C) 2024 Marcus Simonsen - All Rights Reserved
 * Subject to the GNU General Public License
 */
#include <stddef.h>
#ifndef CMATRIX_H_
#define CMATRIX_H_
typedef struct {
  size_t rows;
  size_t cols;
  double *data;
} cmatrix;

cmatrix *cmatrix_zero(size_t rows, size_t cols);
cmatrix *cmatrix_random_uniform(size_t rows, size_t cols);
cmatrix *cmatrix_random_normal(size_t rows, size_t cols, double mean,
                               double standard_deviation);
void cmatrix_free(cmatrix *m);
void cmatrix_print(cmatrix *m);
void cmatrix_set(cmatrix *m, size_t row, size_t col, double val);
double cmatrix_get(cmatrix *m, size_t row, size_t col);
cmatrix *cmatrix_add(cmatrix *m1, cmatrix *m2);
cmatrix *cmatrix_sub(cmatrix *m1, cmatrix *m2);
cmatrix *cmatrix_mul(cmatrix *m1, cmatrix *m2);
cmatrix *cmatrix_mul_scalar(cmatrix *m, double scalar);
cmatrix *cmatrix_transpose(cmatrix *m);

#endif  // CMATRIX_H_
