#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "../include/dbh.h"

const char charTable[] = "0123456789abcdefghijklmnopqrstuvwxyz";

// convert dec to every base from 2 to 36
const char* ConvertDec(double decimalNumber, char** ptr, int base, int* length) {
  char* output = NULL; // doesn't work if not specifed NULL for some fucking stupid reason
  int sizeOfOutput = 0; // initialize as 0 to check later
  int power;
  int multiplicator;
  if (base > 36 || base < 2) { // max and min base
    output = malloc(11);
    strcpy(output, "BASE_ERROR\0");
    return output;
  }
  if (decimalNumber < 0) { // cant deal with negativity
    decimalNumber *= -1;
  }
  if (decimalNumber == 0) { // 0 input error fix
    output = malloc(2);
    strcpy(output, "0\0");
  }
  while (decimalNumber >= 1) {
    power = floor(log10(decimalNumber)/log10(base));
    multiplicator = floor(decimalNumber/pow(base, power));
    if (sizeOfOutput == 0) {
      sizeOfOutput = power + 1; // one bigger because start at 0
    }
    if (output == NULL) { // check if output is assigned
      output = malloc(sizeOfOutput + 1); // + 1 for extra character (char is 1 byte)
      output[sizeOfOutput] = '\0';
      for (int i = 0; i < sizeOfOutput; i++) { // set characters to 0
        strcat(output, "0");
      }
    }
    output[sizeOfOutput - (power+1)] = charTable[multiplicator]; // reverse and convert to char
    decimalNumber -= multiplicator*pow(base, power);
  }
  *length = sizeOfOutput;
  *ptr = output; // be able to free() outside function
  return output;
}

// convert to dec from base 2 to 36
double ConvertToDec(char* xBaseNumber, int base, int size) {
  double output;
  for (int i = 0; i < size; i++) {
    for (int j = 0; i < 36; j++) {
      if (charTable[j] == xBaseNumber[i]) {
        output += j*pow(base, size-i-1);
        break;
      }
    }
  }
  return output;
}

const char* ConvertBase(char** xBaseNumber, int base1, int base2, int* length) {
  double decimalNumber = ConvertToDec(*xBaseNumber, base1, *length);
  ConvertDec(decimalNumber, xBaseNumber, base2, length);
}

// most common uses
const char* BinToHex(char** binaryNumber, int* length) {
  ConvertBase(binaryNumber, 2, 16, length);
}

const char* HexToBin(char** hexadecimalNumber, int* length) {
  ConvertBase(hexadecimalNumber, 16, 2, length);
}

const char* DecToBin(double decimalNumber, char** ptr, int* length) {
  ConvertDec(decimalNumber, ptr, 2, length);
}

const char* DecToHex(double decimalNumber, char** ptr, int* length) {
  ConvertDec(decimalNumber, ptr, 16, length);
}

double BinToDec(char* binaryNumber, int length) {
  return ConvertToDec(binaryNumber, 2, length);
}

double HexToDec(char* hexadecimalNumber, int length) {
  return ConvertToDec(hexadecimalNumber, 6, length);
}
