#ifndef SDDS_SELECTION_H
#define SDDS_SELECTION_H

#include <iostream>
#include <cstring>
using namespace std;

namespace sdds {
    template<typename arrayType, typename keyType>
    int* select(const arrayType array[], const keyType& key, size_t size) {
        int* allocated = new int[size + 1]; 
        int i = 0; 
        for (size_t j = 0; j < size; j++) {
            if (array[j] == key) {
                allocated[i++] = static_cast<int>(j); 
            }
        }
        allocated[i] = -1;
        if (i == 0) {
            delete[] allocated; 
            return nullptr;
        }
        return allocated;
    }

    template<typename arrayType>
    void csvDisplaySelection(const char* title, const arrayType array[], int* indices) {
        cout << title << endl;
        if (indices[0] == -1 || indices == nullptr) {
            cout << "Empty Selection" << endl;
            return;
        }
        for (int i = 0; indices[i] != -1; i++) {
            cout << array[indices[i]];
            if (indices[i + 1] != -1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}
#endif