#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/dbh.h"

int main(int argc, char const *argv[]) {
  // exemple use
  double decimalNumber; // for xToDec functions
  char* outputString; // for string outputs
  int length; // keep track of the output length
  decimalNumber = 345;
  printf("Dec:\t\t%lf\n", decimalNumber);
  DecToBin(decimalNumber, &outputString, &length);
  printf("Bin:\t\t%s\tLength:\t%d\n", outputString, length);
  BinToHex(&outputString, &length);
  printf("Hex:\t\t%s\t\tLength:\t%d\n", outputString, length);
  ConvertBase(&outputString, 16, 12, &length);
  printf("Base 12:\t%s\t\tLength:\t%d\n", outputString, length);
  free(outputString); // allocated memory in function
  return 0;
}
