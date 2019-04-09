#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/dbh.h"

void PrinAll(char** outputString, int base, int*length);
void PrintDecToAll(int decimalNumber, char** output, int* length);

int main(int argc, char *argv[]) {
  // exemple use
  int decimalNumber; // for xToDec functions
  char* outputString; // for string outputs
  int length; // keep track of the output length
  int base; // define number base

  strcpy(outputString, argv[1]);
  base = atoi(argv[2]);
  length = strlen(outputString);

  PrinAll(&outputString, base, &length);

  free(outputString); // allocated memory in function
  return 0;
}

void PrintDecToAll(int decimalNumber, char** output, int* length) {
  for (int i = 2; i <= 36; i++) {
    ConvertDec(decimalNumber, output, i, length);
    if (i < 10) {
      printf("Base 0%d:\t%s\n", i, *output); // to make it look better
    } else {
      printf("Base %d:\t%s\n", i, *output);
    }
  }
}

void PrinAll(char** outputString, int base, int*length) {
  int decimalNumber = ConvertToDec(*outputString, base, *length);
  PrintDecToAll(decimalNumber, outputString, length);
}
