#define _CRT_SECURE_NO_WARNINGS
#include "Container.h"
using namespace std;

namespace sdds {
    Container::Container(const char* desc, int capacity, int volume) {
        if (volume > capacity || desc == nullptr) {
            m_valid = false;
        }
        else {
            this->m_capacity = capacity;
            this->m_contentVolume = volume;
            strcpy(this->m_contentDesc, desc);
            m_valid = true;
        }
    }
    void Container::setEmpty() {
        m_valid = false;
    }
    int Container::capacity() {
        return m_capacity;
    }
    int Container::volume() {
        return m_contentVolume;
    }
    bool Container::valid() {
        return m_valid;
    }
    int Container::operator+=(int c) {
        if (m_contentVolume + c >= m_capacity) {
            c = m_capacity - m_contentVolume;
            m_contentVolume = m_capacity;
        }
        else {
            m_contentVolume += c;
        }
        return c;
    }
    int Container::operator-=(int c) {
        if (m_contentVolume - c >= 0) {
           m_contentVolume -= c;
        }
        else {
           c = m_contentVolume;
           m_contentVolume = 0;
        }
        return c;
    }
    void Container::clear(int capacity, const char* content) {
        int length = strlen(content);
        if (content != nullptr) {
            if (capacity >= 1 && length >= 1) {
                this->m_capacity = capacity;
                this->m_contentVolume = 0;
                strcpy(this->m_contentDesc, content);
                m_valid = true;
            }
        }
    }
    ostream& Container::print(ostream& ostr) {
        if (m_valid) {
            ostr << m_contentDesc << ": (" << m_contentVolume << "cc/" << m_capacity << ")";
        }
        else {
            ostr << "****: (**cc/***)";
        }
        return ostr;
    }
    istream& Container::read(istream& istr) {

        int number;
        if (m_valid) {
            bool loop = false;
            cout << "Add to ";
            print(cout);

            while (!loop) {
                cout << endl << "> ";
                istr >> number;

                if (number < 1 || number > 999) {
                    cout << "Value out of range [1<=val<=999]:";
                }
                else if (number > m_capacity) {
                    cout << "Invalid Integer, retry:";
                }
                else {                
                    loop = true;
                }
            }
            number = (*this += number);
            cout << "Added " << number << " CCs" << endl;
        }
        else {
            cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << endl;
            istr.ignore();
        }
        return istr;
    }
    ostream& operator << (ostream& os, Container& c) {
        return c.print(os);
    }
    istream& operator >> (istream& is, Container& c) {
        return c.read(is);
    }
}