#pragma once

const char* hexTable;

const char* DecToBin(double decimalNumber, char** ptr, int* length);
const char* DecToHex(double decimalNumber, char** ptr, int* length);

double BinToDec(char* binaryNumber, int length);
double HexToDec(char* hexadecimalNumber, int length);

const char* HexToBin(char** hexadecimalNumber, int* length);
const char* BinToHex(char** binaryNumber, int* length);

char* TwosCompliment(char* binaryNumber);

const char* ConvertDec(double decimalNumber, char** ptr, int base, int* length);
double ConvertToDec(char* xBaseNumber, int base, int size);

const char* ConvertBase(char** xBaseNumber, int base1, int base2, int* length);
