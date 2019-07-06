/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include files */
#include "test_Calculation.h"
#include "main.h"
#include "test_Calculation_terminate.h"
#include "test_Calculation_initialize.h"

/* Function Declarations */
static long argInit_int64_T(void);
static double argInit_real_T(void);
static void main_test_Calculation(void);

/* Function Definitions */
static long argInit_int64_T(void)
{
  return 0L;
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void main_test_Calculation(void)
{
  double out;

  /* Initialize function 'test_Calculation' input arguments. */
  /* Call the entry-point 'test_Calculation'. */
  out = test_Calculation(argInit_int64_T(), argInit_real_T());
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  test_Calculation_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_test_Calculation();

  /* Terminate the application.
     You do not need to do this more than one time. */
  test_Calculation_terminate();
  return 0;
}

/* End of code generation (main.c) */
