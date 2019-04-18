#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/Convert.h"
#include "../include/Print.h"
#include "../include/Files.h"

int main(int argc, char *argv[]) {

  char** arr;
  int size;

  ConvertFromFile("input.txt", &arr, 16, &size);

  for (int i = 0; i < size; i++) {
    printf("%s\n", arr[i]);
    free(arr[i]);
  }
  free(arr);

  return 0;
}
