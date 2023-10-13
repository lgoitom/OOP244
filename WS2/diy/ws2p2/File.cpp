/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    int counter() {
        int occurence = 0;
        char ch;

        while (fscanf(fptr, "%c", &ch) == 1) {
            occurence += (ch == '\n');
            //occurence+=occurence;
        }
        rewind(fptr);
        return occurence;
    }
    bool read(char*& postal) {

        char postalC[7] = { '\0' };

        if (fscanf(fptr, "%3s", postalC) == 1) {
            postal = new char[strlen(postalC) + 1];
            strcpy(postal, postalC);
        }

        return postalC[0] != 0;
    }
    bool read(int& population) {
        return fscanf(fptr, "%d\n", &population);

    }

}