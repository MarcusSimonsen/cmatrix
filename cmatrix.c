/* Copyright (C) 2024 Marcus Simonsen - All Rights Reserved
 * Subject to the GNU General Public License
 */
#include "cmatrix.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

cmatrix *cmatrix_zero(size_t rows, size_t cols) {
  double *data = malloc(rows * cols * sizeof(double));
  cmatrix *matrix = malloc(sizeof(cmatrix));

  matrix->rows = rows;
  matrix->cols = cols;
  matrix->data = data;

  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      data[i * cols + j] = 0.0;
    }
  }

  return matrix;
}

double rd() { return (double)rand() / RAND_MAX; }
cmatrix *cmatrix_random_uniform(size_t rows, size_t cols) {
  double *data = malloc(rows * cols * sizeof(double));
  cmatrix *matrix = malloc(sizeof(cmatrix));

  matrix->rows = rows;
  matrix->cols = cols;
  matrix->data = data;

  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      data[i * cols + j] = rd();
    }
  }

  return matrix;
}

double rd_normal(double mean, double standard_deviation) {
  double x = rd();
  double pow = (x - mean) / standard_deviation;
  return 1.0 / (standard_deviation * sqrt(2 * M_PI)) *
         exp(-(1.0 / 2.0) * (pow * pow));
}
cmatrix *cmatrix_random_normal(size_t rows, size_t cols, double mean,
                               double standard_deviation) {
  double *data = malloc(rows * cols * sizeof(double));
  cmatrix *matrix = malloc(sizeof(cmatrix));

  matrix->rows = rows;
  matrix->cols = cols;
  matrix->data = data;

  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      data[i * cols + j] = rd_normal(mean, standard_deviation);
    }
  }

  return matrix;
}

void cmatrix_free(cmatrix *m) {
  free(m->data);
  free(m);
}

void cmatrix_print(cmatrix *m) {
  for (size_t i = 0; i < m->rows; i++) {
    for (size_t j = 0; j < m->cols; j++) {
      printf("%5.3lf ", m->data[i * m->cols + j]);
    }
    printf("\n");
  }
}

void cmatrix_set(cmatrix *m, size_t row, size_t col, double val) {
  m->data[row * m->rows + col] = val;
}

double cmatrix_get(cmatrix *m, size_t row, size_t col) {
  return m->data[row * m->rows + col];
}

cmatrix *cmatrix_add(cmatrix *m1, cmatrix *m2) {
  if (m1->rows != m2->rows || m1->cols != m2->cols)
    return NULL;

  cmatrix *m = cmatrix_zero(m1->rows, m1->cols);

  for (int i = 0; i < m->rows * m->cols; i++)
    for (int j = 0; j < m->rows * m->cols; j++)
      cmatrix_set(m, i, j, cmatrix_get(m1, i, j) + cmatrix_get(m2, i, j));

  return m;
}

cmatrix *cmatrix_sub(cmatrix *m1, cmatrix *m2) {
  if (m1->rows != m2->rows || m1->cols != m2->cols)
    return NULL;

  cmatrix *m = cmatrix_zero(m1->rows, m1->cols);

  for (int i = 0; i < m->rows * m->cols; i++)
    for (int j = 0; j < m->rows * m->cols; j++)
      cmatrix_set(m, i, j, cmatrix_get(m1, i, j) - cmatrix_get(m2, i, j));

  return m;
}

cmatrix *cmatrix_mul(cmatrix *m1, cmatrix *m2) {
  if (m1->cols != m2->rows)
    return NULL;

  cmatrix *m = cmatrix_zero(m1->rows, m2->cols);

  for (int i = 0; i < m1->rows; i++)
    for (int j = 0; j < m2->cols; j++)
      for (int k = 0; k < m1->cols; k++)
        cmatrix_set(m, i, j, cmatrix_get(m1, i, k) + cmatrix_get(m2, k, j));

  return m;
}

cmatrix *cmatrix_mul_scalar(cmatrix *m, double scalar) {
  cmatrix *m_new = cmatrix_zero(m->rows, m->cols);

  for (int i = 0; i < m->rows * m->cols; i++)
    for (int j = 0; j < m->rows * m->cols; j++)
      cmatrix_set(m_new, i, j, cmatrix_get(m, i, j) * scalar);

  return m_new;
}

cmatrix *cmatrix_transpose(cmatrix *m) {
  cmatrix *m_new = cmatrix_zero(m->cols, m->rows);

  for (int i = 0; i < m->rows * m->cols; i++)
    for (int j = 0; j < m->rows * m->cols; j++)
      cmatrix_set(m_new, i, j, cmatrix_get(m, j, i));

  return m_new;
}
