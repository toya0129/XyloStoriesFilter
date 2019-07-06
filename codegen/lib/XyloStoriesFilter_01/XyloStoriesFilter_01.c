/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * XyloStoriesFilter_01.c
 *
 * Code generation for function 'XyloStoriesFilter_01'
 *
 */

/* Include files */
#include "XyloStoriesFilter_01.h"
#include "filter.h"

/* Function Definitions */
double XyloStoriesFilter_01(const double inputData[500])
{
  double out;
  static const double dv0[49] = { 0.0049679352140034232, -0.0013079855171886177,
    -0.0068735340613908617, -0.0028250940455763016, 0.0083663135617343832,
    0.010166648053432096, -0.0058462708174721956, -0.019254534093837747,
    -0.0043454098597987458, 0.024385657561791271, 0.021773141457284935,
    -0.018543979327538603, -0.03986409692104359, -0.0014420123028182831,
    0.048122615821187043, 0.030997037121725621, -0.037907486162757749,
    -0.058269044785412429, 0.0084145364746303544, 0.069477004244358528,
    0.03110308022190128, -0.056414455746156611, -0.064826392648530809,
    0.021686727831943507, 0.078052638758387971, 0.021686727831943507,
    -0.064826392648530809, -0.056414455746156611, 0.03110308022190128,
    0.069477004244358528, 0.0084145364746303544, -0.058269044785412429,
    -0.037907486162757749, 0.030997037121725621, 0.048122615821187043,
    -0.0014420123028182831, -0.03986409692104359, -0.018543979327538603,
    0.021773141457284935, 0.024385657561791271, -0.0043454098597987458,
    -0.019254534093837747, -0.0058462708174721956, 0.010166648053432096,
    0.0083663135617343832, -0.0028250940455763016, -0.0068735340613908617,
    -0.0013079855171886177, 0.0049679352140034232 };

  double dv1[500];
  static const double dv2[49] = { -0.00152818336754993, -0.0023302418294280595,
    0.0017137251272618739, 0.0043060407174671921, -0.0019426608660129885,
    -0.0081910730057441032, 0.00138464468008337, 0.014260455330128497,
    0.0011333555395626569, -0.02209516099852564, -0.0067604990260463011,
    0.030508245626736871, 0.016182694559438996, -0.037724477090114845,
    -0.029254141724035922, 0.041785992872610818, 0.044833343344691072,
    -0.04107799973851773, -0.060900905040619457, 0.034820318527319927,
    0.074950832042514223, -0.023370502475087068, -0.084559403085327875,
    0.0082343953124078256, 0.0879750128802822, 0.0082343953124078256,
    -0.084559403085327875, -0.023370502475087068, 0.074950832042514223,
    0.034820318527319927, -0.060900905040619457, -0.04107799973851773,
    0.044833343344691072, 0.041785992872610818, -0.029254141724035922,
    -0.037724477090114845, 0.016182694559438996, 0.030508245626736871,
    -0.0067604990260463011, -0.02209516099852564, 0.0011333555395626569,
    0.014260455330128497, 0.00138464468008337, -0.0081910730057441032,
    -0.0019426608660129885, 0.0043060407174671921, 0.0017137251272618739,
    -0.0023302418294280595, -0.00152818336754993 };

  double dv3[500];
  static const double dv4[49] = { -0.0015778458543382085, 0.0053091335681012888,
    0.00099132288494504172, -0.0077257381155733046, 3.0053560953886332E-17,
    0.012135515993688223, -0.0023698338751486983, -0.018077739196814692,
    0.0069384953423412641, 0.024647152583588235, -0.014163636569087435,
    -0.030643285258483605, 0.023993494989405915, 0.034792035150562291,
    -0.035817269410062441, -0.035996366212890693, 0.048527850415965718,
    0.033565191421366034, -0.060688874560477918, -0.027372458079925222,
    0.070775899528075115, 0.01791171011199845, -0.077445236804295672,
    -0.0062323106115006162, 0.079777242134122878, -0.0062323106115006162,
    -0.077445236804295672, 0.01791171011199845, 0.070775899528075115,
    -0.027372458079925222, -0.060688874560477918, 0.033565191421366034,
    0.048527850415965718, -0.035996366212890693, -0.035817269410062441,
    0.034792035150562291, 0.023993494989405915, -0.030643285258483605,
    -0.014163636569087435, 0.024647152583588235, 0.0069384953423412641,
    -0.018077739196814692, -0.0023698338751486983, 0.012135515993688223,
    3.0053560953886332E-17, -0.0077257381155733046, 0.00099132288494504172,
    0.0053091335681012888, -0.0015778458543382085 };

  double dv5[500];
  static const double dv6[49] = { 0.00095699230765583423, -0.0054605766929562809,
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

  double dv7[500];
  static const double dv8[49] = { -0.0040161188705125162, 0.0032180252481842473,
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

  double dv9[500];
  static const double dv10[49] = { -0.0034945899440209679, 0.004470982934606329,
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

  double dv11[500];
  static const double dv12[49] = { -0.0027535661429681532, 0.0046181041637266655,
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

  double dv13[500];
  static const double dv14[49] = { 0.0054707968783348111, -0.0057366601329627009,
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

  double dv15[500];

  /* out = zeros(8,1); */
  out = 0.0;

  /* C1 */
  filter(dv0, inputData, dv1);
  if (dv1[0] >= 30.0) {
    /* out(1,1) = 1; */
    out = 1.0;
  }

  /* D */
  filter(dv2, inputData, dv3);
  if (dv3[0] >= 30.0) {
    /* out(2,1) = 2; */
    out = 2.0;
  }

  /* E */
  filter(dv4, inputData, dv5);
  if (dv5[0] >= 30.0) {
    /* out(3,1) = 3; */
    out = 3.0;
  }

  /* F */
  filter(dv6, inputData, dv7);
  if (dv7[0] >= 30.0) {
    /* out(4,1) = 4; */
    out = 4.0;
  }

  /* G */
  filter(dv8, inputData, dv9);
  if (dv9[0] >= 30.0) {
    /* out(5,1) = 5; */
    out = 5.0;
  }

  /* A */
  filter(dv10, inputData, dv11);
  if (dv11[0] >= 30.0) {
    /* out(6,1) = 6; */
    out = 6.0;
  }

  /* B */
  filter(dv12, inputData, dv13);
  if (dv13[0] >= 30.0) {
    /* out(7,1) = 7; */
    out = 7.0;
  }

  /* C2 */
  filter(dv14, inputData, dv15);
  if (dv15[0] >= 30.0) {
    /* out(8,1) = 8; */
    out = 8.0;
  }

  return out;
}

/* End of code generation (XyloStoriesFilter_01.c) */
