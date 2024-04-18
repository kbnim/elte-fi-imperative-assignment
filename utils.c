#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void InitString(char* String, int Size) {
    for (int i = 0; i < Size; i++)
        String[i] = '\0';
}

void CleanInput(char* Input) {
    Input[strlen(Input) - 1] = '\0';
}

void FreeMem(char** Entries, size_t Size) {
    for (size_t i = 0; i < Size; i++)
        free(Entries[i]);
    free(Entries);
}

void PrintStrings(char** Strings, size_t Size) {
    for (size_t i = 0; i < Size; i++)
        printf("%s\n", Strings[i]);
}
