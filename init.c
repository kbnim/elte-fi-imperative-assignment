#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "typedefs.h"
#include "reverse.h"

bool IsLtn(char* Input) {
    return (strcmp(Input, "linenums")) == 0 || (strcmp(Input, "nolinenums")) == 0;
}

bool IsInt(char* MaxLength) {
    size_t StringLength = strlen(MaxLength);
    size_t Counter = 0;

    while (Counter < StringLength && isdigit(MaxLength[Counter]) != 0)
        Counter++;

    return Counter >= StringLength;
}

ltn ConvertToLtn(char* Input) {
    if (strcmp(Input, "linenums") == 0)
        return linenums;
    else if (strcmp(Input, "nolinenums") == 0)
        return nolinenums;
    else
        exit(1);
}

bool CheckArgs(char* Ltn, char* MaxLength) {
    return IsLtn(Ltn) && IsInt(MaxLength);
}

void NoArgs() {
    printf("Usage:\n");
    printf("\trev [SHOW LINE NUMBERS] [MAX LINE LENGTH] files...\n");
}

void RevArgs(int argc, char** argv) {
    data CrucialInfo = { ConvertToLtn(argv[1]), atoi(argv[2]) + 1 };

    if (argc == 3)
        Instructions(stdin, CrucialInfo);
        // NoFileArgs(CrucialInfo);
    else {
        for (int i = 3; i < argc; i++)
            FileArgs(argv[i], CrucialInfo);
    }
}
