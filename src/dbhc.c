#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/Convert.h"
#include "../include/Print.h"
#include "../include/Files.h"

int main(int argc, char *argv[]) {

  char* fileName;
  char** arr;
  int base, lines, length, decimalNumber;

  fileName = "input.txt";
  ReadFile(fileName, &arr, &lines, &base);
  for (int i = 0; i < lines; i++) {
    printf("%s : %d - base: %d - len: %d\n", arr[i], ConvertToDec(arr[i], base, strlen(arr[i])), base, strlen(arr[i]));
    free(arr[i]);
  }
  free(arr);

  char* num = "00101110101";
  int base2 = 2;
  int length2 = 11;
  printf("%s : %d\n", num, ConvertToDec(num, base2, length2));

  return 0;
}
