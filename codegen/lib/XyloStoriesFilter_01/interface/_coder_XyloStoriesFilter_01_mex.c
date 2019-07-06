/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_XyloStoriesFilter_01_mex.c
 *
 * Code generation for function '_coder_XyloStoriesFilter_01_mex'
 *
 */

/* Include files */
#include "_coder_XyloStoriesFilter_01_api.h"
#include "_coder_XyloStoriesFilter_01_mex.h"

/* Function Declarations */
static void c_XyloStoriesFilter_01_mexFunct(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[1]);

/* Function Definitions */
static void c_XyloStoriesFilter_01_mexFunct(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[1])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        20, "XyloStoriesFilter_01");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 20,
                        "XyloStoriesFilter_01");
  }

  /* Call the function. */
  XyloStoriesFilter_01_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(XyloStoriesFilter_01_atexit);

  /* Module initialization. */
  XyloStoriesFilter_01_initialize();

  /* Dispatch the entry-point. */
  c_XyloStoriesFilter_01_mexFunct(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  XyloStoriesFilter_01_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_XyloStoriesFilter_01_mex.c) */
