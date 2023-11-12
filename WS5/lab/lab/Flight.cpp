/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title , "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title,title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator bool() const {
        if (m_passengers > 0 && m_fuel >= (600 * double(m_passengers))) {
            return true;
        }
        return false;
    }

    Flight::operator int() const {
        return m_passengers;
    }

    Flight::operator double() const {
        return m_fuel;
    }

    Flight::operator const char* ()const {
        return m_title;
    }

    bool Flight::operator~() const {
        if (m_passengers == 0) {
            return true;
        }
        return false;
    }

    Flight& Flight::operator=(Flight& flightObj) {
        m_fuel = flightObj.m_fuel;
        m_passengers = flightObj.m_passengers;
        strcpy(m_title, flightObj.m_title);

        flightObj.emptyPlane();

        return* this;
    }

    Flight& Flight::operator=(int numPassengers) {
        if (numPassengers <= Boen747Capacity && numPassengers > 0) {
            m_passengers = numPassengers;
        }

        return *this;
    }

    Flight& Flight::operator=(double numFuel) {
        if (numFuel <= FuelTankCapacity && numFuel > 0) {
            m_fuel = numFuel;
        }

        return *this;
    }

    Flight& Flight::operator+=(double addFuel) {
        if (addFuel > 0 && (m_fuel + addFuel) <= FuelTankCapacity) {
            m_fuel += addFuel;
        }

        return *this;
    }

    Flight& Flight::operator+=(int addPassengers) {
        if (addPassengers > 0 && (m_passengers + addPassengers) <= Boen747Capacity) {
            m_passengers += addPassengers;
        }

        return *this;
    }

    Flight& Flight::operator-=(double removeFuel) {
        if (removeFuel <= m_fuel && m_fuel >= 0) {
            m_fuel -= removeFuel;
        }

        return *this;
    }

    Flight& Flight::operator-=(int removePassengers) {
        if (m_passengers > 0 && removePassengers <= m_passengers && removePassengers > 0) {
            m_passengers -= removePassengers;
        }

        return *this;
    }

    Flight& Flight::operator << (Flight& movingLeft) {
        int total = movingLeft.m_passengers + m_passengers;

        if (movingLeft) {
            if (&movingLeft != this) {

                if (total <= Boen747Capacity) {
                    m_passengers = total;
                    movingLeft.m_passengers = (total > Boen747Capacity) ? (total - Boen747Capacity) : 0;
                }
            }

        }

        return *this;
    }

    Flight& Flight::operator >> (Flight& movingRight) {
        int total = movingRight.m_passengers + m_passengers;
        

        if (movingRight) {
            if (&movingRight != this) {

                if (total >= Boen747Capacity) {
                    movingRight.m_passengers = total;
                    m_passengers = (total > Boen747Capacity) ? (total - Boen747Capacity) : 0;
                    movingRight.m_passengers = Boen747Capacity;
                }
            }

        }

        return *this;
    }

    int Flight::operator +(const Flight& checkOtherFlight) {
        int passengerTotal;

        if (checkOtherFlight.m_passengers && this->m_passengers) {
            passengerTotal = this->m_passengers + checkOtherFlight.m_passengers;

        }
        else {
            passengerTotal = 0;
        }

        return passengerTotal;
        
    }

    int operator+=(int &leftRef, const Flight& rightRef) {
        
        
        return leftRef+=int(rightRef);
    }
}