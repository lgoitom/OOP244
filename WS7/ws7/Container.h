#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

namespace sdds {
    class Container {
    private:
        bool m_valid;
        char m_contentDesc[50];
        double m_contentVolume;
        double m_capacity;
    protected:
        int capacity();
        int volume();
        void setEmpty();
    public:
        Container(const char* desc, int capacity, int volume = 0);
        int operator+=(int c);
        int operator-=(int c);
        void clear(int capacity, const char* content);
        bool valid();
        ostream& print(ostream& out);
        istream& read(istream& in);
        friend ostream& operator << (ostream& os, Container& c);
        friend istream& operator >> (istream& is, Container& c);
    };
}
#endif