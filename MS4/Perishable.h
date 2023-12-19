#ifndef PERISHABLE_H
#define PERISHABLE_H
#include "Item.h"
#include "Date.h"

using namespace std;
namespace sdds {
    class Perishable : public Item {
        char* m_handlingInstructions;
        Date m_expiryDate;

    public:
        Perishable();
        ~Perishable();
        Perishable(const Perishable&);
        Perishable& operator=(const Perishable&);
        Date& expiry();
        int readSku(istream& istr);
        ofstream& save(ofstream& ofstr) const;
        ifstream& load(ifstream& ifstr);
        ostream& display(ostream& ostr) const;
        istream& read(istream& istr);
    };
}

#endif
