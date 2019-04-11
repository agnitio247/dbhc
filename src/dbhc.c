#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/dbh.h"

#define MAX_BASE 36
#define BUFFER 50

void PrinAll(char** outputString, int base, int* length);
void PrintDecToAll(int decimalNumber, char** output, int* length);
char** ReadFile(char* filename, char** output, int* length, int* size, int* base);
void WriteToFile(char* filename, char** input);

int main(int argc, char *argv[]) {
  // exemple use
  int decimalNumber; // for xToDec functions
  char* outputString; // for string outputs
  int length; // keep track of the output length
  int base; // define number base

  char** output;
  int size;

  output = ReadFile("input.txt", output, &length, &size, &base);
  printf("Size:\t%d\t\tBase:\t%d\n", size, base);
  printf("%s\n", output[0]);

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

char** ReadFile(char* filename, char** output, int* length, int* size, int* base) {
  char buffer[BUFFER];
  int maxLine, inputBase, currentLine, maxLength;
  FILE* file = fopen(filename, "r");
  fscanf(file, "%d %d %d", &maxLine, &maxLength, &inputBase); // get file parameters
  *length = maxLength; // to keep track of string length
  *size = maxLine;
  *base = inputBase;
  output = (char**)malloc(maxLine*sizeof(char)); // i know sizeof(char) == 1
  for (int i = 0; i < maxLine; i++) { // allocate each string in array
    output[i] = (char*)malloc(maxLength*sizeof(char) + 1);
  }
  currentLine = 0; // keep track of where we are
  if (file != NULL) { // NULL if file error
    while (fscanf(file, "%s", buffer) == 1 && currentLine < maxLine) {
      strcpy(output[currentLine], buffer);
      strcat(output[currentLine], "\0");
      printf("%c\n", output[currentLine][0]);
      currentLine++;
    }
    fclose(file);
  } else {
    //return "FILE_ERROR";
  }
  return output;
}
