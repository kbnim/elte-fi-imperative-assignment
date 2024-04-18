#ifndef REVERSE_H
#define REVERSE_H

#include <stdio.h>

#include "typedefs.h"

// HEADER FILE CONTAINING FUNCTIONS
// RELATED TO THE PROCESS OF REVERSING

void ReverseItem(char* Entry);

void Reverse(char** NewEntries, ltn ShowLineNumbers, size_t Count);

char **GetContents(FILE* Source, int Max, size_t* Ptr_Total, size_t* Ptr_Count, char** NewEntries);

void Instructions(FILE* Source, data CrucialInfo);

void FileArgs(char* FileName, data CrucialInfo);

#endif
