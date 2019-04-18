#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/Convert.h"
#include "../include/Print.h"
#include "../include/Files.h"

int main(int argc, char *argv[]) {

  int decNum, length, size, base;
  char* fileName;
  char** arr;

  ReadFile(fileName, &arr, &size, &base);

  for (int i = 0; i < size; i++) {
    length = strlen(arr[i]);
    ConvertToDec(arr[i], &decNum, base, length);
    printf("%s : %d\n", arr[i], decNum);
    free(arr[i]);
  }
  free(arr);

  return 0;
}
