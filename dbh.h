#pragma once

const char* hexTable;

const char* DecToBin(double decimalNumber, char** ptr);
const char* DecToHex(double decimalNumber, char** ptr);

const char* BinToDec(double binaryNumber);
const char* BinToHex(double binaryNumber);
const char* HexToDec(double hexadecimalNumber);
const char* HexToBin(double hexadecimalNumber);

const char* TwosCompliment(double binaryNumber);
