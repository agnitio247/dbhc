#include <stdio.h>
#include <stdlib.h>

#include "../include/Print.h"
#include "../include/Convert.h"

void PrintDecToAll(int decimalNumber, char** output, int* length) {
  for (int i = 2; i <= MAX_BASE; i++) {
    ConvertDec(decimalNumber, output, i, length);
    if (i < 10) {
      printf("Base 0%d:\t%s\n", i, *output); // to make it look better
    } else {
      printf("Base %d:\t%s\n", i, *output);
    }
  }
}

void PrintAll(char** outputString, int base, int* length) {
  int decimalNumber;
  ConvertToDec(*outputString, &decimalNumber, base, *length);
  PrintDecToAll(decimalNumber, outputString, length);
}
