#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/Files.h"

char* ReadFile(const char* fileName, char*** ptr, int* linesPtr, int* basePtr) {
  int lines, bufferLength, base, currentLine;
  char buffer[BUFFER_SIZE]; // change value in header file
  FILE* file = fopen("input.txt", "r"); // open in read mode
  if (fscanf(file, "%d %d", &lines, &base) == 2) {
  } else {
    return "FILE_ERROR";
  }
  char** arr = (char**)malloc(sizeof(char*)*lines); // array of strings (char pointers)
  currentLine = 0; // keep track of line
  while (fscanf(file, "%s", buffer) == 1 && currentLine < lines) { // stop at indicated line in file
    bufferLength = strlen(buffer);
    arr[currentLine] = (char*)malloc(sizeof(char)*(bufferLength+1)); // + 1 for null char
    strcpy(arr[currentLine], strcat(buffer, "\0"));
    currentLine++;
  }
  *ptr = arr;
  *linesPtr = lines; // keep track of number of lines
  *basePtr = base; // keep track of input base
  fclose(file);
}
