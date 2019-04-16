#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/Convert.h"
#include "../include/Print.h"
#include "../include/Files.h"

int main(int argc, char *argv[]) {

  int lines, maxLength, base, currentLine;

  char** ptr;

  ReadFile("input.txt", &ptr, &lines, &maxLength, &base);

  for (int i = 0; i < lines; i++) {
    printf("%s\n", ptr[i]);
    free(ptr[i]);
  }

  return 0;
}
