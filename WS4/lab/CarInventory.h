#ifndef SDDS_CARINVENTORY_H_
#define SDDS_CARINVENTORY_H_

#include <iostream>
#include <iomanip>

namespace sdds {

    class CarInventory {
    private:
        char* m_type;
        char* m_brand;
        char* m_model;
        int m_year;
        int m_code;
        double m_price;

        // Private member function to reset the information
        void resetInfo();

    public:
        // Constructors
        CarInventory();
        CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1.0);
        CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);

        // Destructor
        ~CarInventory();

        // Public member functions
        void printInfo() const;
        bool isValid() const;
        bool isSimilarTo(const CarInventory& car) const;

    };

    int find_similar(CarInventory car[], const int num_cars);

 // CARINVENTORY_H


}

#endif