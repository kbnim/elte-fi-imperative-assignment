#ifndef INIT_H
#define INIT_H

#include <stdbool.h>

#include "typedefs.h"

// HEADER FILE CONTAINING FUNCTIONS
// RELATED TO THE INITIALISATION PROCESS

bool IsLtn(char* Input);

bool IsInt(char *MaxLength);

ltn ConvertToLtn(char *Input);

bool CheckArgs(char* Ltn, char* MaxLength);

void NoArgs();

void RevArgs(int argc, char** argv);

#endif
