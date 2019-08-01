/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_XyloStoriesFilter_api.h
 *
 * Code generation for function '_coder_XyloStoriesFilter_api'
 *
 */

#ifndef _CODER_XYLOSTORIESFILTER_API_H
#define _CODER_XYLOSTORIESFILTER_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_XyloStoriesFilter_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern real_T XyloStoriesFilter(real_T inputData[500]);
extern void XyloStoriesFilter_api(const mxArray * const prhs[1], int32_T nlhs,
  const mxArray *plhs[1]);
extern void XyloStoriesFilter_atexit(void);
extern void XyloStoriesFilter_initialize(void);
extern void XyloStoriesFilter_terminate(void);
extern void XyloStoriesFilter_xil_terminate(void);

#endif

/* End of code generation (_coder_XyloStoriesFilter_api.h) */
