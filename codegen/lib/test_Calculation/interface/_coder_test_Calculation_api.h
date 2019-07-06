/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_test_Calculation_api.h
 *
 * Code generation for function '_coder_test_Calculation_api'
 *
 */

#ifndef _CODER_TEST_CALCULATION_API_H
#define _CODER_TEST_CALCULATION_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_test_Calculation_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern real_T test_Calculation(int64_T mode, real_T num);
extern void test_Calculation_api(const mxArray * const prhs[2], int32_T nlhs,
  const mxArray *plhs[1]);
extern void test_Calculation_atexit(void);
extern void test_Calculation_initialize(void);
extern void test_Calculation_terminate(void);
extern void test_Calculation_xil_terminate(void);

#endif

/* End of code generation (_coder_test_Calculation_api.h) */
