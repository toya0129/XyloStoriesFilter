/* input convert string to double
* size  : size of received data to sensor
* input : received data to sensor
* out   : data converted string to double
*/

/* Include files */
#include "DataConversion.h"

void DataConversion(const int size, char* input, double output[100]){
  int j = 0, k = 0, printSize = 0;
  char change[100];

  // inputData convert string to double
  for(int i = 0; i < size; i++){
    if(input[i] == 10){
      output[k] = atof(change);
      memset(change,0,sizeof(change));
      k += 1;
      j = 0;
    }else{
      change[j] = input[i];
      j += 1;
    }
  }

  // Print Data
  printSize = sizeof(*output) / sizeof( output[0]);
  for (int i = 0; i < size; i++){
    printf("%f \n",output[i]);
  }
}
