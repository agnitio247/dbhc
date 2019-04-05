#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "dbh.h"

const char* DecToBin(double decimalNumber) {

  char* output;

  if (decimalNumber == 0) return 0;
  double power = floor(log10(decimalNumber)/log10(2));
  int sizeOfOutput = power + 1;

  output = malloc(sizeof(char)*power+1);

  for (int i = 0; i < sizeOfOutput; i++) {
    strcat(output, "0");
  }

  return output;
}
