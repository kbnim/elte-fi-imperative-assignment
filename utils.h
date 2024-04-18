#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

// HEADER FILE CONTAINING COMMONLY USED FUNCTIONS
// RELATED TO SMALL ALGORITHMS OR "DEBUGGING"

void InitString(char* String, int Size);

void CleanInput(char* Input);

void FreeMem(char** Entries, size_t Size);

void PrintStrings(char** Strings, size_t Size);

#endif
