#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "dbh.h"

const char* DecToBin(double decimalNumber, char** ptr) {
  char* output = NULL; // doesn't work if not specifed NULL for some fucking stupid reason
  int sizeOfOutput = 0; // initialize as 0 to check later
  int power;
  if (decimalNumber == 0) { // 0 input error fix
    output = malloc(2);
    strcpy(output, "0\0");
  }
  while (decimalNumber != 0) {
    power = floor(log10(decimalNumber)/log10(2));
    if (sizeOfOutput == 0) {
      sizeOfOutput = power + 1; // one bigger because start at 0
    }
    if (output == NULL) { // check if output is assigned
      output = malloc(sizeOfOutput + 1); // + 1 for extra character (char is 1 byte)
      output[sizeOfOutput] = '\0';
      for (int i = 0; i < sizeOfOutput; i++) { // set characters to 0
        strcat(output, "0");
      }
    }
    output[sizeOfOutput - (power+1)] = '1';
    decimalNumber -= pow(2, power);
  }
  *ptr = output; // be able to free() outside function
  printf("%lf\n", decimalNumber);
  return output;
}
