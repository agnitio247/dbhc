#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/Files.h"
#include "../include/Convert.h"

// TODO: fix mem leak
char* ReadFile(const char* fileName, char*** ptr, int* basePtr, int* linesPtr) {
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

// TODO: realloc each string
char* ConvertFromFile(const char* fileName, char*** ptr, int base, int* linesPtr) {
  int basePtr, lines, length;
  char** arr;
  ReadFile(fileName, &arr, &basePtr, &lines); // get input from file
  for (int i = 0; i < lines; i++) {
    length = strlen(arr[i]);
    ConvertBase(&arr[i], basePtr, base, &length); // convert it
  }
  *linesPtr = lines;
  *ptr = arr;
}

char* WriteToFile(const char* fileName, char** arr, int base, int length) {
  FILE* file = fopen(fileName, "a"); // append mode
  char firstLine[BUFFER_SIZE]; // change value in Convert header file
  sprintf(firstLine, "%d %d\n", length, base);
  fputs(firstLine, file); // first line of file
  for (int i = 0; i < length; i++){
    fputs(strcat(arr[i], "\n"), file);
  }
  fclose(file);
}
