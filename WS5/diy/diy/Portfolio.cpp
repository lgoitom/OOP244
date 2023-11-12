/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.cpp
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
#include "Portfolio.h"

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
       emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const{
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Value: ";
            cout.width(10);
            cout << double(*this);
            cout << " | ";
            cout << " Type: ";
            cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio::operator double() const {
        return m_value;
    }

    Portfolio::operator const char* () const {
        return m_stock;
    }

    Portfolio::operator char() const {
        return m_type;
    }

    Portfolio::operator bool() const {
        if (m_type == 'G' || m_type == 'V' || m_type == 'I') {
            return true;
        }
        return false;
    }

    Portfolio& Portfolio::operator +=(double value) {
        if (value >= 0) {
            if (m_type != 'E') {
                m_value += value;

            }
        }

        return *this;
    }

    Portfolio& Portfolio::operator-=(double value) {

        int total = m_value - value;
        if (value >= 0 && total >= 0) {
            m_value = m_value - value;
        }

        return *this;
    }

    bool Portfolio::operator~() const {
        if (m_value < 0) {
            return true;
        }

        return false;
    }

    Portfolio& Portfolio::operator<<(Portfolio& movingLeft) {
        int total = m_value + movingLeft.m_value;
        if (m_value > 0 && movingLeft.m_value > 0) {
            if (&movingLeft != this) {
                m_value = total;
                movingLeft.emptyPortfolio();
            }
        }
        return *this;
    }

    Portfolio& Portfolio::operator>>(Portfolio& movingRight) {
        int total = movingRight.m_value + m_value;
        if (m_value > 0 && movingRight.m_value > 0) {
            if (&movingRight != this) {
                movingRight.m_value = total;
                this->emptyPortfolio();
            }
        }

        return *this;
    }


    double operator+(const Portfolio& left, const Portfolio& right){
        
        if (left && right) {
            return double(left) + double(right);
        }
        else {
            return 0;
        }

      
    }

    double operator+=(double& left, const Portfolio& right){
        left += double(right);
        return left;
    }

}