/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#include "Population.h"
#include "File.h"
#include <iostream>
#include <cstring>
namespace sdds {
    bool startsWith(const char* cstring, const char* subString) {
        return std::strstr(cstring, subString) == cstring;
    }
    bool getPostalCode(char* postal_code_prefix) {
        std::cout << "Population report" << endl;
        std::cout << "-----------------" << endl;
        std::cout << "Enter postal code:" << endl;
        std::cout << "> " << endl;
        std::cin >> postal_code_prefix;

        if (*postal_code_prefix = '!') {
            return false;
        }
        else {
            return true;
        }

    }
    bool load(const char* filename) {
        if (openFile("PCpopulations.csv")) {
            return true;
        }

        return false;

    }
    void display() {

    }
    void deallocateMemory() {

    }



}