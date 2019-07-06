/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_XyloStoriesFilter_2_mex.c
 *
 * Code generation for function '_coder_XyloStoriesFilter_2_mex'
 *
 */

/* Include files */
#include "_coder_XyloStoriesFilter_2_api.h"
#include "_coder_XyloStoriesFilter_2_mex.h"

/* Function Declarations */
static void XyloStoriesFilter_2_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[1]);

/* Function Definitions */
static void XyloStoriesFilter_2_mexFunction(int32_T nlhs, mxArray *plhs[1],
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
                        19, "XyloStoriesFilter_2");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 19,
                        "XyloStoriesFilter_2");
  }

  /* Call the function. */
  XyloStoriesFilter_2_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(XyloStoriesFilter_2_atexit);

  /* Module initialization. */
  XyloStoriesFilter_2_initialize();

  /* Dispatch the entry-point. */
  XyloStoriesFilter_2_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  XyloStoriesFilter_2_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_XyloStoriesFilter_2_mex.c) */
