#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dbh.h"

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    printf("%s\n", "must input something");
    exit(0);
  }
  double input;
  sscanf(argv[1], "%lf", &input);
  if (strcmp(argv[1], "0") != 0 && atoi(argv[1]) == 0) {
    fprintf(stderr, "%s\n", "input must be a valid number");
    exit(0);
  }
  char* number;
  ConvertDec(input, &number, 2);
  printf("%s\n", number);
  ConvertDec(input, &number, 16);
  printf("%s\n", number);
  free(number);
  return 0;
}
