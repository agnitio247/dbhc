#pragma once

const char* hexTable;

const char* DecToBin(double decimalNumber, char** ptr);
const char* DecToHex(double decimalNumber, char** ptr);

double BinToDec(char* binaryNumber);
const char* BinToHex(char* binaryNumber);
double HexToDec(char* hexadecimalNumber);
const char* HexToBin(char* hexadecimalNumber);

char* TwosCompliment(char* binaryNumber);

const char* ConvertDec(double decimalNumber, char** ptr, int base);
double ConvertToDec(char* xBaseNumber, int base, int size);

const char* ConvertBase(char* xBaseNumber, int base1, int base2);
