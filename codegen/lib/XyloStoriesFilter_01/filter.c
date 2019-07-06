/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * filter.c
 *
 * Code generation for function 'filter'
 *
 */

/* Include files */
#include <string.h>
#include "XyloStoriesFilter_01.h"
#include "filter.h"

/* Function Definitions */
void filter(const double b[49], const double x[500], double y[500])
{
  int k;
  int b_k;
  int j;
  memset(&y[0], 0, 500U * sizeof(double));
  for (k = 0; k < 49; k++) {
    b_k = k + 1;
    for (j = b_k; j < 501; j++) {
      y[j - 1] += b[k] * x[(j - k) - 1];
    }
  }
}

/* End of code generation (filter.c) */
