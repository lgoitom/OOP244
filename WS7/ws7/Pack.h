#ifndef SDDS_PACK_H
#define SDDS_PACK_H

#include <cstring>
#include <string>
#include "Container.h"
using namespace sdds;

namespace sdds {
    class Pack : public Container {
    private:
        int m_size;
        int m_unitSize;
        int m_numUnits;
    public:
        Pack(const char* content, int size, int unitSize = 330, int units = 0);
        int unit();
        int size();
        int noOfUnits();
        int operator+=(int units);
        int operator-=(int units);
        void clear(int pack, int unitSize, const char* content);
        ostream& print(ostream& ostr);
        istream& read(istream& istr);
        friend ostream& operator << (ostream& os, Pack& p);
        friend istream& operator >> (istream& is, Pack& p);
    };
}
#endif