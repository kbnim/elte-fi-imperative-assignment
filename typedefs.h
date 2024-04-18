#ifndef TYPEDEFS_H
#define TYPEDEFS_H

// HEADER FILE CONTAINING TYPE DEFINITIONS

#include <limits.h>

enum LinesToNumber {linenums, nolinenums};
typedef enum LinesToNumber ltn;

struct DataBase {
    ltn ShowLineNumbers;
    int MaxLineLength;
};
typedef struct DataBase data;

#endif
