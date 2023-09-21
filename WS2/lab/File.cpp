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
// Name                Date            Reason
// Luwam Goitom-Worre  Sept. 21, 2023  completing workshop
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
    //global variable
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
   bool read(char*& name) {
       char empName[128] = { '\0' };

           if (fscanf(fptr, "%127[^\n]\n", empName) == 1) {
               name = new char[strlen(empName) + 1];
               strcpy(name, empName);
           }
       return empName[0] != 0;
   }
   bool read(int& employeeNum) {
       if (fscanf(fptr, "%d,", &employeeNum) == 1) {
           return true;
       }
      return false;
   }
   bool read(double& salary) {
       if (fscanf(fptr, "%lf,", &salary) == 1) {
           return true;
       }
       return false;
   }
   
}