/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * XyloStoriesFilter.c
 *
 * Code generation for function 'XyloStoriesFilter'
 *
 */

/* Include files */
#include <string.h>
#include "XyloStoriesFilter.h"
#include "XyloStoriesFilter_emxutil.h"
#include "filter.h"

/* Function Definitions */
void XyloStoriesFilter(const emxArray_real_T *inputData, double out[8])
{
  emxArray_real_T *band;
  int i0;
  int nx_m_nb;
  unsigned int inputData_idx_0;
  int nx;
  int k;
  int j;
  int naxpy;
  static const double dv0[49] = { 0.00095699230765583423, -0.0054605766929562809,
    0.0013826886861341525, 0.0070646618189667684, -0.00570209257271588,
    -0.0081944950153267967, 0.013042427365788346, 0.0060234714959727991,
    -0.022281518173291517, 0.0020936045941334449, 0.029966225222222878,
    -0.016820938042238588, -0.031459722838243338, 0.035716464027032761,
    0.023001395880500562, -0.0534739526912974, -0.003767276032318603,
    0.063613538760322511, -0.02307767075061485, -0.061001411168056983,
    0.050954479236970947, 0.044128947199285957, -0.071978256642082933,
    -0.016111890102372989, 0.07979560563819213, -0.016111890102372989,
    -0.071978256642082933, 0.044128947199285957, 0.050954479236970947,
    -0.061001411168056983, -0.02307767075061485, 0.063613538760322511,
    -0.003767276032318603, -0.0534739526912974, 0.023001395880500562,
    0.035716464027032761, -0.031459722838243338, -0.016820938042238588,
    0.029966225222222878, 0.0020936045941334449, -0.022281518173291517,
    0.0060234714959727991, 0.013042427365788346, -0.0081944950153267967,
    -0.00570209257271588, 0.0070646618189667684, 0.0013826886861341525,
    -0.0054605766929562809, 0.00095699230765583423 };

  static const double dv1[49] = { -0.0040161188705125162, 0.0032180252481842473,
    0.0023615759632994423, -0.0068742120628170382, 0.002702189874761258,
    0.0085702359497867517, -0.012281482152930208, -0.0021807372003338869,
    0.020572963784903558, -0.014981404041996497, -0.016117850391277264,
    0.03432529406588921, -0.0074946130739012226, -0.038118485747366662,
    0.040691737268460426, 0.013765151647591347, -0.0597303062121698,
    0.031199561494703255, 0.043936982297362946, -0.069063211611437331,
    0.0047563541915301754, 0.070810565310127763, -0.058383627220447321,
    -0.029893961071798428, 0.08158061045586508, -0.029893961071798428,
    -0.058383627220447321, 0.070810565310127763, 0.0047563541915301754,
    -0.069063211611437331, 0.043936982297362946, 0.031199561494703255,
    -0.0597303062121698, 0.013765151647591347, 0.040691737268460426,
    -0.038118485747366662, -0.0074946130739012226, 0.03432529406588921,
    -0.016117850391277264, -0.014981404041996497, 0.020572963784903558,
    -0.0021807372003338869, -0.012281482152930208, 0.0085702359497867517,
    0.002702189874761258, -0.0068742120628170382, 0.0023615759632994423,
    0.0032180252481842473, -0.0040161188705125162 };

  static const double dv2[49] = { -0.0034945899440209679, 0.004470982934606329,
    -0.0017139980640511192, -0.0040486479714772258, 0.00874468311610693,
    -0.0065379551188504276, -0.0043309941930002663, 0.016548323084334359,
    -0.017184154544029259, -1.1589659228683813E-17, 0.024336096316391716,
    -0.033234768880536392, 0.012359926187098006, 0.026537117660598273,
    -0.050298978512968363, 0.032535099442544325, 0.0186048339540915,
    -0.061594276512597787, 0.055766070523089704, -5.1228162522845055E-17,
    -0.0612841735973995, 0.074430234737247525, -0.024749998521189649,
    -0.047732913529821383, 0.081582597554062386, -0.047732913529821383,
    -0.024749998521189649, 0.074430234737247525, -0.0612841735973995,
    -5.1228162522845055E-17, 0.055766070523089704, -0.061594276512597787,
    0.0186048339540915, 0.032535099442544325, -0.050298978512968363,
    0.026537117660598273, 0.012359926187098006, -0.033234768880536392,
    0.024336096316391716, -1.1589659228683813E-17, -0.017184154544029259,
    0.016548323084334359, -0.0043309941930002663, -0.0065379551188504276,
    0.00874468311610693, -0.0040486479714772258, -0.0017139980640511192,
    0.004470982934606329, -0.0034945899440209679 };

  static const double dv3[49] = { -0.0027535661429681532, 0.0046181041637266655,
    -0.0048608544353074407, 0.002535797949007408, 0.0027024332206583702,
    -0.0093921048793693309, 0.0139057895641695, -0.011911858751198198,
    0.0013338074293819675, 0.014982753193379592, -0.02913793136450803,
    0.031621352718280843, -0.0170312521423996, -0.011228499409380031,
    0.04069540176569067, -0.055246421948938841, 0.043891538359228204,
    -0.0081176216898101918, -0.036937317885267433, 0.069069431103763124,
    -0.070436501779197, 0.0377047989242748, 0.015008857185098192,
    -0.062576014062803234, 0.081587957203414566, -0.062576014062803234,
    0.015008857185098192, 0.0377047989242748, -0.070436501779197,
    0.069069431103763124, -0.036937317885267433, -0.0081176216898101918,
    0.043891538359228204, -0.055246421948938841, 0.04069540176569067,
    -0.011228499409380031, -0.0170312521423996, 0.031621352718280843,
    -0.02913793136450803, 0.014982753193379592, 0.0013338074293819675,
    -0.011911858751198198, 0.0139057895641695, -0.0093921048793693309,
    0.0027024332206583702, 0.002535797949007408, -0.0048608544353074407,
    0.0046181041637266655, -0.0027535661429681532 };

  static const double dv4[49] = { 0.0054707968783348111, -0.0057366601329627009,
    0.004697157578893215, -0.0018126114942041062, -0.0031838509738589022,
    0.0096157893142900276, -0.015542344350975151, 0.018129807163605478,
    -0.014727422393328008, 0.0042655977900568354, 0.011665582097031259,
    -0.028678470819451213, 0.040681857591274434, -0.0419769606867726,
    0.029631624446133577, -0.0051706043276437217, -0.025227545050250419,
    0.052318226263899731, -0.066757490062621813, 0.062444747744971,
    -0.038997535988646088, 0.002353624273939852, 0.036851876915965122,
    -0.066660804952658317, 0.077764514434381482, -0.066660804952658317,
    0.036851876915965122, 0.002353624273939852, -0.038997535988646088,
    0.062444747744971, -0.066757490062621813, 0.052318226263899731,
    -0.025227545050250419, -0.0051706043276437217, 0.029631624446133577,
    -0.0419769606867726, 0.040681857591274434, -0.028678470819451213,
    0.011665582097031259, 0.0042655977900568354, -0.014727422393328008,
    0.018129807163605478, -0.015542344350975151, 0.0096157893142900276,
    -0.0031838509738589022, -0.0018126114942041062, 0.004697157578893215,
    -0.0057366601329627009, 0.0054707968783348111 };

  memset(&out[0], 0, sizeof(double) << 3);
  emxInit_real_T(&band, 1);

  /* C1 */
  filter(inputData, band);
  i0 = band->size[0];
  for (nx_m_nb = 0; nx_m_nb < i0; nx_m_nb++) {
    if (band->data[nx_m_nb] >= 30.0) {
      out[0] = 1.0;
    }
  }

  /* D */
  b_filter(inputData, band);
  i0 = band->size[0];
  for (nx_m_nb = 0; nx_m_nb < i0; nx_m_nb++) {
    if (band->data[nx_m_nb] >= 30.0) {
      out[1] = 2.0;
    }
  }

  /* E */
  c_filter(inputData, band);
  i0 = band->size[0];
  for (nx_m_nb = 0; nx_m_nb < i0; nx_m_nb++) {
    if (band->data[nx_m_nb] >= 30.0) {
      out[2] = 3.0;
    }
  }

  /* F */
  inputData_idx_0 = (unsigned int)inputData->size[0];
  i0 = band->size[0];
  band->size[0] = (int)inputData_idx_0;
  emxEnsureCapacity_real_T(band, i0);
  nx = inputData->size[0];
  nx_m_nb = band->size[0];
  i0 = band->size[0];
  band->size[0] = nx_m_nb;
  emxEnsureCapacity_real_T(band, i0);
  for (i0 = 0; i0 < nx_m_nb; i0++) {
    band->data[i0] = 0.0;
  }

  if (inputData->size[0] >= 98) {
    for (k = 0; k < 49; k++) {
      nx_m_nb = k + 1;
      for (j = nx_m_nb; j <= nx; j++) {
        band->data[j - 1] += dv0[k] * inputData->data[(j - k) - 1];
      }
    }
  } else {
    if (inputData->size[0] > 49) {
      nx_m_nb = inputData->size[0] - 50;
    } else {
      nx_m_nb = -1;
    }

    for (k = 0; k <= nx_m_nb; k++) {
      for (j = 0; j < 49; j++) {
        i0 = k + j;
        band->data[i0] += inputData->data[k] * dv0[j];
      }
    }

    naxpy = inputData->size[0] - nx_m_nb;
    i0 = nx_m_nb + 2;
    for (k = i0; k <= nx; k++) {
      for (j = 0; j <= naxpy - 2; j++) {
        nx_m_nb = (k + j) - 1;
        band->data[nx_m_nb] += inputData->data[k - 1] * dv0[j];
      }

      naxpy--;
    }
  }

  i0 = band->size[0];
  for (nx_m_nb = 0; nx_m_nb < i0; nx_m_nb++) {
    if (band->data[nx_m_nb] >= 30.0) {
      out[3] = 4.0;
    }
  }

  /* G */
  inputData_idx_0 = (unsigned int)inputData->size[0];
  i0 = band->size[0];
  band->size[0] = (int)inputData_idx_0;
  emxEnsureCapacity_real_T(band, i0);
  nx = inputData->size[0];
  nx_m_nb = band->size[0];
  i0 = band->size[0];
  band->size[0] = nx_m_nb;
  emxEnsureCapacity_real_T(band, i0);
  for (i0 = 0; i0 < nx_m_nb; i0++) {
    band->data[i0] = 0.0;
  }

  if (inputData->size[0] >= 98) {
    for (k = 0; k < 49; k++) {
      nx_m_nb = k + 1;
      for (j = nx_m_nb; j <= nx; j++) {
        band->data[j - 1] += dv1[k] * inputData->data[(j - k) - 1];
      }
    }
  } else {
    if (inputData->size[0] > 49) {
      nx_m_nb = inputData->size[0] - 50;
    } else {
      nx_m_nb = -1;
    }

    for (k = 0; k <= nx_m_nb; k++) {
      for (j = 0; j < 49; j++) {
        i0 = k + j;
        band->data[i0] += inputData->data[k] * dv1[j];
      }
    }

    naxpy = inputData->size[0] - nx_m_nb;
    i0 = nx_m_nb + 2;
    for (k = i0; k <= nx; k++) {
      for (j = 0; j <= naxpy - 2; j++) {
        nx_m_nb = (k + j) - 1;
        band->data[nx_m_nb] += inputData->data[k - 1] * dv1[j];
      }

      naxpy--;
    }
  }

  i0 = band->size[0];
  for (nx_m_nb = 0; nx_m_nb < i0; nx_m_nb++) {
    if (band->data[nx_m_nb] >= 30.0) {
      out[4] = 5.0;
    }
  }

  /* A */
  inputData_idx_0 = (unsigned int)inputData->size[0];
  i0 = band->size[0];
  band->size[0] = (int)inputData_idx_0;
  emxEnsureCapacity_real_T(band, i0);
  nx = inputData->size[0];
  nx_m_nb = band->size[0];
  i0 = band->size[0];
  band->size[0] = nx_m_nb;
  emxEnsureCapacity_real_T(band, i0);
  for (i0 = 0; i0 < nx_m_nb; i0++) {
    band->data[i0] = 0.0;
  }

  if (inputData->size[0] >= 98) {
    for (k = 0; k < 49; k++) {
      nx_m_nb = k + 1;
      for (j = nx_m_nb; j <= nx; j++) {
        band->data[j - 1] += dv2[k] * inputData->data[(j - k) - 1];
      }
    }
  } else {
    if (inputData->size[0] > 49) {
      nx_m_nb = inputData->size[0] - 50;
    } else {
      nx_m_nb = -1;
    }

    for (k = 0; k <= nx_m_nb; k++) {
      for (j = 0; j < 49; j++) {
        i0 = k + j;
        band->data[i0] += inputData->data[k] * dv2[j];
      }
    }

    naxpy = inputData->size[0] - nx_m_nb;
    i0 = nx_m_nb + 2;
    for (k = i0; k <= nx; k++) {
      for (j = 0; j <= naxpy - 2; j++) {
        nx_m_nb = (k + j) - 1;
        band->data[nx_m_nb] += inputData->data[k - 1] * dv2[j];
      }

      naxpy--;
    }
  }

  i0 = band->size[0];
  for (nx_m_nb = 0; nx_m_nb < i0; nx_m_nb++) {
    if (band->data[nx_m_nb] >= 30.0) {
      out[5] = 6.0;
    }
  }

  /* B */
  inputData_idx_0 = (unsigned int)inputData->size[0];
  i0 = band->size[0];
  band->size[0] = (int)inputData_idx_0;
  emxEnsureCapacity_real_T(band, i0);
  nx = inputData->size[0];
  nx_m_nb = band->size[0];
  i0 = band->size[0];
  band->size[0] = nx_m_nb;
  emxEnsureCapacity_real_T(band, i0);
  for (i0 = 0; i0 < nx_m_nb; i0++) {
    band->data[i0] = 0.0;
  }

  if (inputData->size[0] >= 98) {
    for (k = 0; k < 49; k++) {
      nx_m_nb = k + 1;
      for (j = nx_m_nb; j <= nx; j++) {
        band->data[j - 1] += dv3[k] * inputData->data[(j - k) - 1];
      }
    }
  } else {
    if (inputData->size[0] > 49) {
      nx_m_nb = inputData->size[0] - 50;
    } else {
      nx_m_nb = -1;
    }

    for (k = 0; k <= nx_m_nb; k++) {
      for (j = 0; j < 49; j++) {
        i0 = k + j;
        band->data[i0] += inputData->data[k] * dv3[j];
      }
    }

    naxpy = inputData->size[0] - nx_m_nb;
    i0 = nx_m_nb + 2;
    for (k = i0; k <= nx; k++) {
      for (j = 0; j <= naxpy - 2; j++) {
        nx_m_nb = (k + j) - 1;
        band->data[nx_m_nb] += inputData->data[k - 1] * dv3[j];
      }

      naxpy--;
    }
  }

  i0 = band->size[0];
  for (nx_m_nb = 0; nx_m_nb < i0; nx_m_nb++) {
    if (band->data[nx_m_nb] >= 30.0) {
      out[6] = 7.0;
    }
  }

  /* C2 */
  inputData_idx_0 = (unsigned int)inputData->size[0];
  i0 = band->size[0];
  band->size[0] = (int)inputData_idx_0;
  emxEnsureCapacity_real_T(band, i0);
  nx = inputData->size[0];
  nx_m_nb = band->size[0];
  i0 = band->size[0];
  band->size[0] = nx_m_nb;
  emxEnsureCapacity_real_T(band, i0);
  for (i0 = 0; i0 < nx_m_nb; i0++) {
    band->data[i0] = 0.0;
  }

  if (inputData->size[0] >= 98) {
    for (k = 0; k < 49; k++) {
      nx_m_nb = k + 1;
      for (j = nx_m_nb; j <= nx; j++) {
        band->data[j - 1] += dv4[k] * inputData->data[(j - k) - 1];
      }
    }
  } else {
    if (inputData->size[0] > 49) {
      nx_m_nb = inputData->size[0] - 50;
    } else {
      nx_m_nb = -1;
    }

    for (k = 0; k <= nx_m_nb; k++) {
      for (j = 0; j < 49; j++) {
        i0 = k + j;
        band->data[i0] += inputData->data[k] * dv4[j];
      }
    }

    naxpy = inputData->size[0] - nx_m_nb;
    i0 = nx_m_nb + 2;
    for (k = i0; k <= nx; k++) {
      for (j = 0; j <= naxpy - 2; j++) {
        nx_m_nb = (k + j) - 1;
        band->data[nx_m_nb] += inputData->data[k - 1] * dv4[j];
      }

      naxpy--;
    }
  }

  i0 = band->size[0];
  for (nx_m_nb = 0; nx_m_nb < i0; nx_m_nb++) {
    if (band->data[nx_m_nb] >= 30.0) {
      out[7] = 8.0;
    }
  }

  emxFree_real_T(&band);
}

/* End of code generation (XyloStoriesFilter.c) */
