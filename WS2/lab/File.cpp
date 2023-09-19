/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   // TODO: read functions go here    
   bool read(FILE* fptr, const char filename[], int records /*char*& name*/) {
       char name[128]{};
       int i;

       for (i = 0, i < *&noOfRecords; i++;) {
           if (fscanf(fptr, "%127[^\n]\n", &name) == 1) {
               //name == new char
               //strcpy
               char *j = new char;
               char* &name = j;
               return true;
           }

       }
       return false;
   }
   /*bool read(................) {
      return .....
   }
   bool read(................) {
      return .....
   }
   */
}