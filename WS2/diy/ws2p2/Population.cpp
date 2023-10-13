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
#define _CRT_SECURE_NO_WARNINGS
#include "Population.h"
#include "File.h"
#include <iostream>
#include <cstring>
namespace sdds {

    PostalCode* pCode;

    int times;
    void sort() {
        int i, j;
        PostalCode temp;
        for (i = times - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (pCode[j].population > pCode[j + 1].population) {
                    temp = pCode[j];
                    pCode[j] = pCode[j + 1];
                    pCode[j + 1] = temp;
                }
            }
        }
    }
    bool load(PostalCode& postal) {
        bool ok = false;

        for (int i = 0; i < times; i++) {

            if (read(postal.population) && read(postal.postCode)) {

                ok = true;
            }
        }
        // return the combined success result of the three read functions. These read 
        // functions should set the properties of the reference argument of the load function
        return ok;
    }
    bool startsWith(const char* cstring, const char* subString) {
        return std::strstr(cstring, subString) == cstring;
    }
    
    bool load(const char* filename, const char* partial_postal_code_prefix) {
       
        bool ok = false;
        int match = 0;
        int population;

        if (openFile("PCpopulations.csv")) {
            times = counter();
            pCode = new PostalCode[times];


            int i;
            for (i = 0; i < times; i++) {

                if (load(pCode[i])) {
                    if (startsWith(pCode[i].postCode, partial_postal_code_prefix)) {
                        strcpy(pCode[i].postCode, partial_postal_code_prefix);
                        population = pCode[i].population;
                        match++;
                        ok = true;
                    }
                }
                else {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted.\n";
                    delete[] pCode;
                }
            }
            closeFile();
        }
        else {
            cout << "Could not open data file: PCpopulations.csv" << endl;
        }

        return ok;
       
    }

   
    bool getPostalCode(char* postal_code_prefix) {
        std::cout << "Population report" << endl;
        std::cout << "-----------------" << endl;
        std::cout << "Enter postal code:" << endl;
        std::cout << "> ";
        std::cin >> postal_code_prefix; //everytime there is valid input it goes straight to the first case

        
        if (strcmp(postal_code_prefix, "!") == 0) {
            return false;
        }
       
            return true;

    }
    void display() {
        //getPostalCode(pCode->postCode);
        int i;
        int j = 0;

        std::cout << "Postal Code: population" << endl;
        std::cout << "-------------------------" << endl;
        sort();
        for (i = 0; i < times; i++) {
            cout << i + 1 << "- ";
            cout.put(*pCode[i].postCode);
            cout << ": ";
            cout.put(pCode[i].population);
            cout << endl;
            j += pCode[i].population;
        }
        std::cout << "-------------------------" << endl;
        std::cout << "Population of the listed areas: ";
        cout.put(j);
        std::cout << endl;
        std::cout << endl;

    }

    void deallocateMemory() {
        delete[] pCode;
        pCode = nullptr;
    }



}