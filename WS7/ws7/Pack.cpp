#define _CRT_SECURE_NO_WARNINGS
#include "Pack.h"
using namespace std;

namespace sdds {
    Pack::Pack(const char* content, int size, int unitSize, int units) : Container(content, size* unitSize, unitSize* units) {
        this->m_numUnits = units;
        this->m_size = size;
        this->m_unitSize = unitSize;
    }
    int Pack::unit() {
        return m_unitSize;
    }

    int Pack::noOfUnits() {
        return m_numUnits;
    }

    int Pack::size() {
        return m_size;
    }
    int Pack::operator+=(int units) {
        int num = Container::operator+=(units * m_unitSize) / m_unitSize;
        this->m_numUnits += num;
        return num;
    }
    int Pack::operator-=(int units) {
        int num = Container::operator-=(units * m_unitSize) / m_unitSize;
        this->m_numUnits -= num;
        return num;
    }
    void Pack::clear(int pack, int unitSize, const char* content) {
        if (unitSize > 0) {
            int pUnit = pack * unitSize;
            m_size = pack;
            this->m_unitSize = unitSize;
            this->m_numUnits = 0;
            Container::clear(pUnit, content);
        }
    }
    istream& Pack::read(istream& istr) {

        if (m_numUnits == m_size) {
            cout << "Pack is full! Press <ENTER> to continue..." << endl;
            istr.ignore();
        }
        else if (valid()){
            cout << "Add to ";
            print(cout);
            cout << endl << "> ";

            int max = m_size - m_numUnits;
            int val;

            while (true) {
                istr >> val;
                if (val > m_size) {
                    cout << "Invalid Integer, retry: ";
                }
                else if (val < 1 || val > max) {
                    cout << "Value out of range [1<=val<=" << max << "]: ";
                }
                else {                 
                    break;
                }
            }
            int newVal = *this += val;
            cout << "Added " << newVal << endl;
        }
        else  {
            cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
            istr.ignore();
        }

        return istr;
    }
    ostream& Pack::print(ostream& ostr) {
        Container::print(ostr);
        if (valid()) {
            ostr << ", " << m_numUnits << " in a pack of " << m_size;
        }

        return ostr;
    }
    ostream& operator << (ostream& os, Pack& p) {
        return p.print(os);
    }
    istream& operator >> (istream& is, Pack& p) {
        return p.read(is);
    }
}