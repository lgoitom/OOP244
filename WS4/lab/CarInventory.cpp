#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>

#include "CarInventory.h"

namespace sdds {
    void CarInventory::resetInfo() {
        
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        
        m_year = 0;
        m_code = 0;
        m_price = 0.0;
    }

    CarInventory::CarInventory() {
        resetInfo();
    }

    CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
        resetInfo();

            m_type = new char[strlen(type) + 1];
            strcpy(m_type, type);
        
            m_brand = new char[strlen(brand) + 1];
            strcpy(m_brand, brand);
        
            m_model = new char[strlen(model) + 1];
            strcpy(m_model, model);
        

            m_year = (year < 1990) ? 2022 : year;  
            m_code = (code < 100 || code > 999) ? 100 : code;  
            m_price = (price <= 0) ? 1.0 : price;  
    }

    CarInventory::~CarInventory() {
        delete[] m_brand;
        delete[] m_type;
        delete[] m_model;
    }


    CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {

        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;
        resetInfo();
        m_year = year;
        m_code = code;
        m_price = price;
        m_type = new char[strlen(type) + 1];
        m_brand = new char[strlen(brand) + 1];
        m_model = new char[strlen(model) + 1];
        strcpy(m_type, type);
        strcpy(m_brand, brand);
        strcpy(m_model, model);
        
       
        return *this;
    }

    void CarInventory::printInfo() const {
        std::cout << "| " << std::setw(10) << std::left << m_type
            << " | " << std::setw(16) << std::left << m_brand
            << " | " << std::setw(16) << std::left << m_model
            << " | " << std::setw(4) << m_year
            << " |  " << std::setw(3) << m_code
            << " |" << std::setw(10) << std::right << std::fixed << std::setprecision(2) << m_price << " |" << std::endl;
    }

    bool CarInventory::isValid() const {
        if (m_type && m_brand && m_model && m_year >= 1990 && (m_code >= 100 && m_code <= 999)) {
            return true;
        }
        return false;
    }

    bool CarInventory::isSimilarTo(const CarInventory& car) const {

        if (isValid()) {
            return car.isValid() && (strcmp(m_brand, car.m_brand) == 0) && (strcmp(m_model, car.m_model) == 0)  
                && (strcmp(m_type, car.m_type) == 0) && m_year == car.m_year;

        }
        return false;
    }

    int find_similar(CarInventory car[], const int num_cars) {
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (car[i].isSimilarTo(car[j])) {
                    return i;
                }
            }
        }
        return -1;
    }


}

