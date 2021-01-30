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
#include "XyloStoriesFilter.h"
#include "filter.h"

/* Function Definitions */
// void filter(const double b[49], const double x[], double y[], unsigned int size)
// {
//   int k;
//   int b_k;
//   int j;
//
//   // def size = 100U
//   memset(&y[0], 0, size * sizeof(double));
//   for (k = 0; k < 49; k++) {
//     b_k = k + 1;
//     for (j = b_k; j < size + 1; j++) {
//       y[j - 1] += b[k] * x[(j - k) - 1];
//     }
//   }
// }

void filter(const double b[49], const double x[], double y[], unsigned int size)
{
  int k;
  int b_k;
  int j;
  int t = size + 1;

  // def size = 100U
  memset(&y[0], 0, size * sizeof(double));
  for (k = 0; k < 49; k++) {
    b_k = k + 1;
    for (j = b_k; j < t ; j++) {
      y[j - 1] += b[k] * x[(j - k) - 1];
    }
  }
}

/* End of code generation (filter.c) */
