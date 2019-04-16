#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/Files.h"

char* ReadFile(const char* fileName, char*** ptr, int* linesPtr, int* maxLengthPtr, int* basePtr) {
  int lines, maxLength, base, currentLine;
  char buffer[BUFFER_SIZE]; // change value in header file
  FILE* file = fopen("input.txt", "r");
  if (fscanf(file, "%d %d %d", &lines, &maxLength, &base) == 3) {
  } else {
    return "FILE_ERROR";
  }
  char** arr = (char**)malloc(sizeof(char*)*lines);
  currentLine = 0;
  while (fscanf(file, "%s", buffer) == 1 && currentLine < lines) {
    arr[currentLine] = (char*)malloc(sizeof(char)*(maxLength+1));
    strcpy(arr[currentLine], strcat(buffer, "\0"));
    currentLine++;
  }
  *ptr = arr;
  *linesPtr = lines;
  *maxLengthPtr = maxLength;
  *basePtr = base;
  fclose(file);
}
