#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "typedefs.h"
#include "utils.h"

void ReverseItem(char* Entry) {
    size_t Length = strlen(Entry);

    for (size_t i = 0; i < (Length / 2); i++) {
        char Temp = Entry[i];
        Entry[i] = Entry[Length - 1 - i];
        Entry[Length - 1 - i] = Temp;
    }
}

void Reverse(char** NewEntries, ltn ShowLineNumbers, size_t Count) {
    for (size_t i = 0; i < Count; i++)
        ReverseItem(NewEntries[i]);

    // for the sake of avoiding warnings,
    // Count needs to be cast to type 'int'
    for (int i = (int)Count - 1; i >= 0; i--) {
        if (ShowLineNumbers == linenums)
            printf("%d ", i + 1);
        printf("%s\n", NewEntries[i]);
    }
}

char **GetContents(FILE* Source, int Max, size_t* Ptr_Total, size_t* Ptr_Count, char** NewEntries) {
    NewEntries = malloc(sizeof(char*) * (*Ptr_Total));

    if (NewEntries == NULL) {
        puts("Memory allocation failed!");
        return NULL;
    }

    int Increment = 2;
    char LineSegment[Max];
    InitString(LineSegment, Max);

    int Character = getc(Source);
    int Index = 0;

    while (Character != EOF) {
        if (Character != '\n') {
            // filling up temporary array until it encounters a '\n'
            // also, leaves space for '\0' (hence it's "Max - 1")
            if (Index < Max - 1) {
                LineSegment[Index] = Character;
                Index++;
            }
        } else {
            // doubling size of allocated memory when insufficient
            if (*Ptr_Count == *Ptr_Total) {
                *Ptr_Total *= Increment;
                NewEntries = realloc(NewEntries, sizeof(char*) * (*Ptr_Total));

                if (NewEntries == NULL) {
                    puts("Memory allocation failed!");
                    return NULL;
                }
            }

            NewEntries[*Ptr_Count] = malloc(sizeof(char) * Max);

            if (NewEntries[*Ptr_Count] == NULL) {
                puts("Memory allocation failed!");
                return NULL;
            }

            strcpy(NewEntries[*Ptr_Count], LineSegment);
            (*Ptr_Count)++;

            // reinitialising 'LineSegment' for next use
            InitString(LineSegment, Max);
            Index = 0;
        }
        Character = getc(Source);
    }

    // if the size of the allocated memory exceeds the number of lines,
    // it initialises the remaining entries to NULL (so that 'valgrind' won't throw an error)
    if (*Ptr_Count < *Ptr_Total) {
        for (size_t i = *Ptr_Count; i < *Ptr_Total; i++)
            NewEntries[i] = NULL;
    }

    return NewEntries;
}

void Instructions(FILE* Source, data CrucialInfo) {
    size_t Count = 0;
    size_t Total = 1;

    size_t* Ptr_Count = &Count;
    size_t* Ptr_Total = &Total;

    char** NewEntries = NULL;
    NewEntries = GetContents(Source, CrucialInfo.MaxLineLength, Ptr_Total, Ptr_Count, NewEntries);
    Reverse(NewEntries, CrucialInfo.ShowLineNumbers, Count);
    FreeMem(NewEntries, Total);
}

void FileArgs(char* FileName, data CrucialInfo) {
    FILE* SourceFile = fopen(FileName, "r");

    if (SourceFile == NULL) {
        printf("File opening unsuccessful: %s\n", FileName);
        return;
    }

    Instructions(SourceFile, CrucialInfo);
    fclose(SourceFile);
}
