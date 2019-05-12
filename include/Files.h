#pragma once

#define BUFFER_SIZE 50

char* ReadFile(const char* fileName, char*** ptr, int* basePtr, int* linesPtr);

char* ConvertFromFile(const char* fileName, char*** ptr, int base, int* linesPtr);

char* WriteToFile(const char* fileName, char** arr, int base, int length);
