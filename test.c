#include "cmatrix.c"
#include <stdio.h>

#define SIZE 0.05
#define TEST_DIST_AMOUNT 1000000

void test_zero() {
  cmatrix *m = cmatrix_zero(3, 2);

  cmatrix_print(m);

  cmatrix_free(m);
}

void test_random_uniform() {
  printf("Test of zero initialization of matrix\n");
  cmatrix *m = cmatrix_random_uniform(3, 2);

  cmatrix_print(m);

  cmatrix_free(m);
}

void test_uniform_distribution() {
  printf("Test of uniform random function\n");
  int amount = 1 / SIZE;
  int counts[amount];
  for (int i = 0; i < amount; i++) {
    counts[i] = 0;
  }

  for (int i = 0; i < TEST_DIST_AMOUNT; i++) {
    counts[(int)(rd() * amount)]++;
  }

  for (int i = 0; i < amount; i++) {
    printf("%i\n", counts[i]);
  }
}

void test_normal_distribution() {
  printf("Test of normal random function\n");
  int amount = (int)(1 / SIZE);
  int counts[amount];
  for (int i = 0; i < amount; i++) {
    counts[i] = 0;
  }

  for (int i = 0; i < TEST_DIST_AMOUNT; i++) {
    counts[(int)(rd_normal(0, 0.4) * amount)]++;
  }

  for (int i = 0; i < amount; i++) {
    printf("%i\n", counts[i]);
  }
}

int main() {
  test_uniform_distribution();
  test_normal_distribution();

  return 0;
}
