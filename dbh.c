#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "dbh.h"

const char charTable[] = "0123456789abcdefghijklmnopqrstuvwxyz";

// convert dec to every base from 2 to 36
const char* ConvertDec(double decimalNumber, char** ptr, int base) {
  char* output = NULL; // doesn't work if not specifed NULL for some fucking stupid reason
  int sizeOfOutput = 0; // initialize as 0 to check later
  int power;
  int multiplicator;
  if (base > 36 || base < 2) { // max and min base
    output = malloc(11);
    strcpy(output, "BASE_ERROR\0");
    return output;
  }
  if (decimalNumber < 0) { // cant deal with negativity
    decimalNumber *= -1;
  }
  if (decimalNumber == 0) { // 0 input error fix
    output = malloc(2);
    strcpy(output, "0\0");
  }
  while (decimalNumber >= 1) {
    power = floor(log10(decimalNumber)/log10(base));
    multiplicator = floor(decimalNumber/pow(base, power));
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
    output[sizeOfOutput - (power+1)] = charTable[multiplicator]; // reverse and convert to char
    decimalNumber -= multiplicator*pow(base, power);
  }
  *ptr = output; // be able to free() outside function
  return output;
}

// convert to dec from base 2 to 36
double ConvertToDec(char* xBaseNumber, int base, int size) {
  double output;
  for (int i = 0; i < size; i++) { // nested for loops cuz thats how it is
    for (int j = 0; j < 36; i++) { // really need to optimize this somehow
      if (charTable[j] == xBaseNumber[i]) { // this is really bad
        output += j*i;
        break;
      }
    }
  }
  return output;
}
