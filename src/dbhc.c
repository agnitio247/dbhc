#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/dbh.h"

#define MAX_BASE 36
#define BUFFER_SIZE 50

void PrinAll(char** outputString, int base, int* length);
void PrintDecToAll(int decimalNumber, char** output, int* length);
char* ReadFile(const char* fileName, char*** ptr, int* linesPtr, int* maxLengthPtr, int* basePtr);

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

void PrintDecToAll(int decimalNumber, char** output, int* length) {
  for (int i = 2; i <= MAX_BASE; i++) {
    ConvertDec(decimalNumber, output, i, length);
    if (i < 10) {
      printf("Base 0%d:\t%s\n", i, *output); // to make it look better
    } else {
      printf("Base %d:\t%s\n", i, *output);
    }
  }
}

void PrinAll(char** outputString, int base, int* length) {
  int decimalNumber = ConvertToDec(*outputString, base, *length);
  PrintDecToAll(decimalNumber, outputString, length);
}

char* ReadFile(const char* fileName, char*** ptr, int* linesPtr, int* maxLengthPtr, int* basePtr) {
  int lines, maxLength, base, currentLine;
  char buffer[BUFFER_SIZE];
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
