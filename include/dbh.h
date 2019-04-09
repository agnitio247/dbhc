#pragma once

// base functions
const char* ConvertDec(int decimalNumber, char** ptr, int base, int* length);
int ConvertToDec(char* xBaseNumber, int base, int size);

const char* ConvertBase(char** xBaseNumber, int base1, int base2, int* length);

// most commonly used functions
const char* BinToHex(char** binaryNumber, int* length);
const char* HexToBin(char** hexadecimalNumber, int* length);

const char* DecToBin(int decimalNumber, char** ptr, int* length);
const char* DecToHex(int decimalNumber, char** ptr, int* length);

int BinToDec(char* binaryNumber, int length);
int HexToDec(char* hexadecimalNumber, int length);
