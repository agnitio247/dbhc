#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/dbh.h"

#define MAX_BASE 36
#define BUFFER_SIZE 50

void PrinAll(char** outputString, int base, int* length);
void PrintDecToAll(int decimalNumber, char** output, int* length);
char* ReadFile(char* filename, char*** outputArray, int* size, int* base);

int main(int argc, char *argv[]) {

  int decimalNumber, size, length, base;
  char* outputString;
  char** outputArray;

  if (ReadFile("input.txt", &outputArray, &size, &base) != "ERROR") {
    printf("%s\n", "success");
    printf("%s\n", outputArray[0]);
    printf("%s\n", outputArray[1]);
    printf("%s\n", outputArray[2]);
    printf("%s\n", *(outputArray+3));
    printf("%s\n", *(outputArray+4));
    printf("%s\n", *(outputArray+5));
    printf("%s\n", *(outputArray+6));
    printf("%s\n", *(outputArray+7));
  } else {
    printf("%s\n", "Error opening file");
  }

  return 0;
}

char* ReadFile(char* filename, char*** outputArray, int* size, int* base) {
  char buffer[BUFFER_SIZE];
  int maxLine, inputBase, currentLine, maxLength;
  FILE* file = fopen(filename, "r");
  if (file != NULL) { // NULL if file error
    fscanf(file, "%d %d %d", &maxLine, &maxLength, &inputBase); // get file parameters
    char* output[maxLine]; // create output
    currentLine = 0; // keep track of position
    while (fscanf(file, "%s", buffer) == 1 && currentLine < maxLine) { // check errors
      output[currentLine] = (char*)malloc(sizeof(char)*(maxLength+1)); //
      strcpy(output[currentLine], strcat(buffer, "\0")); // need last char to be null
      currentLine++;
    }
    *outputArray = output;
    *size = maxLine;
    *base = inputBase;
    printf("%s\n", *((*outputArray)+3));
    fclose(file);
    return "SUCCESS";
  } else { // if file not found
    return "ERROR";
    fclose(file);
  }
}
