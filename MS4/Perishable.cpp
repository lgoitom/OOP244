#include <iostream>
#include <fstream>
#include <cstring>
#include "Perishable.h"
#include "Utils.h"

using namespace std;
namespace sdds {

    Perishable::Perishable() {
        m_handlingInstructions = nullptr;
        new (&m_expiryDate) Date();
    }


    Perishable::Perishable(const Perishable& obj) : Item(obj) {

            m_expiryDate = obj.m_expiryDate;

            if (obj.m_handlingInstructions != nullptr) {
                m_handlingInstructions = new char[strlen(obj.m_handlingInstructions) + 1];
                for (int i = 0; i < (int)strlen(obj.m_handlingInstructions) + 1; i++)
                    m_handlingInstructions[i] = obj.m_handlingInstructions[i];
            }
            else {
                m_handlingInstructions = nullptr;
            }

    }

    Perishable& Perishable::operator=(const Perishable& obj) {
        if (this != &obj) {
            (Item&)*this = obj;

            delete[] m_handlingInstructions;

            if (obj.m_handlingInstructions != nullptr) {
                m_handlingInstructions = new char[strlen(obj.m_handlingInstructions) + 1];
                strcpy(m_handlingInstructions, obj.m_handlingInstructions);
            }
            else {
                m_handlingInstructions = nullptr;
            }
            m_expiryDate = obj.m_expiryDate;
        }

        return *this;
    }

    Date& Perishable::expiry() {
        return m_expiryDate;
    }

    int Perishable::readSku(istream& istr) {
        m_sku = ut.getint(10000, 39999, "SKU: ");
        return m_sku;
    }

    ofstream& Perishable::save(ofstream& ofstr) const {
        const_cast<Date&>(m_expiryDate).formatted(false);
        Item::save(ofstr);
        if (m_handlingInstructions != nullptr) {
            ofstr << '\t' << m_handlingInstructions << '\t';
            m_expiryDate.write(ofstr);
        }
        else {
            ofstr << '\t' << '\t';
            m_expiryDate.write(ofstr);
        }

        return ofstr;
    }

    ifstream& Perishable::load(ifstream& ifstr) {
        char temp[500];

        Item::load(ifstr);
        if (ifstr.peek() != '\t') {
            ifstr.get(temp, 500, '\t');
            delete[] m_handlingInstructions;
            if (temp != nullptr) {
                m_handlingInstructions = new char[strlen(temp) + 1];
                strcpy(m_handlingInstructions, temp);
            }
        }
        else {
            delete[] m_handlingInstructions;
            m_handlingInstructions = nullptr;
        }
        if (ifstr.peek() != '\t') {
            m_state = "Input file stream read (perishable) failed!";
            ifstr.ignore(2000, '\n');
        }
        else {
            ifstr.ignore();
            m_expiryDate.read(ifstr);
        }

        return ifstr;
    }

    ostream& Perishable::display(ostream& ostr) const {
        const_cast<Date&>(m_expiryDate).formatted(true);
        if (!this) {
            ostr << m_state;
        }
        else {
            if (m_linear == true) {
                Item::display(ostr);
                ostr << (m_handlingInstructions && m_handlingInstructions[0] != '\0' ? "*" : " ");
                m_expiryDate.write(ostr);
            }
            else {
                ostr << "Perishable ";
                Item::display(ostr);
                ostr << "Expiry date: ";
                ostr << m_expiryDate << endl;
                if (m_handlingInstructions != nullptr && m_handlingInstructions[0] != '\0') {
                    ostr << "Handling Instructions: " << m_handlingInstructions << endl;
                }
            }
        }

        return ostr;
    }

    istream& Perishable::read(istream& istr) {
        char temp[500];

        Item::read(istr);
        delete[] m_handlingInstructions;
        m_handlingInstructions = nullptr;

        istr.ignore();
        cout << "Expiry date (YYMMDD): ";
        istr >> m_expiryDate;
        cout << "Handling Instructions, ENTER to skip: ";
        istr.get(temp, 500, '\n');
        if (temp[0] != '\0') {
            if (temp != nullptr) {
                /*m_handlingInstructions = new char[strlen(temp) + 1];
                strcpy(m_handlingInstructions, temp);*/
                ut.alocpy(m_handlingInstructions, temp);
            }
        }
        if (!istr) {
            m_state = "Perishable console date entry failed!";
        }
        istr.ignore(2000, '\n');

        return istr;
    }
    Perishable::~Perishable() {
        delete[] m_handlingInstructions;
        m_handlingInstructions = nullptr;
    }
};
