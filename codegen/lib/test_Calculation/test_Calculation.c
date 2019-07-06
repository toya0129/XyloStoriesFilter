/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * test_Calculation.c
 *
 * Code generation for function 'test_Calculation'
 *
 */

/* Include files */
#include "test_Calculation.h"

/* Function Definitions */
double test_Calculation(long mode, double num)
{
  double out;
  if (mode == 1L) {
    out = 5.0 + num;
  } else if (mode == 2L) {
    out = 5.0 - num;
  } else if (mode == 3L) {
    out = 5.0 * num;
  } else if (mode == 4L) {
    out = 5.0 / num;
  } else {
    out = num;
  }

  return out;
}

/* End of code generation (test_Calculation.c) */
