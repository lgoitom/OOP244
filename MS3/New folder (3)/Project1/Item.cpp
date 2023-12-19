#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include "Item.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
    Item::Item(){
        m_description = nullptr;
        m_flag = false;
        m_price = 0.0;
        m_quantityOnHand= 0;
        m_quantityNeeded = 0;
        m_state = nullptr;
    }
    int Item::readSku(std::istream& is)
    {
        m_skuNum = ut.getInt(40000, 99999, "SKU: ");
        return m_skuNum;
    }
    void Item::linear(bool valid)
    {
        m_flag = valid;
    }
    int Item::qtyNeeded() const
    {
        return m_quantityNeeded;
    }
    int Item::qty() const
    {
        return m_quantityOnHand;
    }
    Item::operator double() const
    {
        return m_price;
    }
    Item::operator bool() const
    {
        return m_state == nullptr;
    }
    int Item::operator-=(int quantity)
    {
        return m_quantityOnHand-= quantity;
    }
    int Item::operator+=(int quantity)
    {
        return m_quantityOnHand+= quantity;
    }

    bool Item::operator==(int sku) const
    {
        return m_skuNum == sku;
    }
    bool Item::operator==(const char* description) const
    {
        return (ut.strStr(m_description, description) != nullptr);
    }
    std::ofstream& Item::save(std::ofstream& os) const
    {
         os << m_skuNum << "\t" << m_description << "\t" << m_quantityOnHand
                << "\t" << m_quantityNeeded << "\t" << m_price << endl;
        return os;
    }
    std::ifstream& Item::load(std::ifstream& is)
    {
        delete[] m_description;
        int sku;
        int qty;
        int qtyneeded;
        double price;
        char description[900];

        if (!is.fail())
        {
            is >> sku;
            ut.extractChar(is, '\t');
            is.get(description, 900, '\t');
            ut.extractChar(is, '\t');
            is >> qty;
            ut.extractChar(is, '\t');
            is >> qtyneeded;
            ut.extractChar(is, '\t');
            is >> price;
            ut.extractChar(is, '\n');

            m_description = new char[strlen(description) + 1];
            strcpy(m_description, description);
            m_skuNum = sku;
            m_quantityNeeded = qtyneeded;
            m_quantityOnHand= qty;
            m_price = price;
        } else {
            cout << "Input file stream read failed!" << endl;
        }
        return is;
    }
    std::ostream& Item::display(std::ostream& os) const
    {
        char str[1000] = {};
		if (!m_flag) {
			os << "AMA Item:" << endl;
			os << m_skuNum << ": " << m_description << endl;
			os << "Quantity Needed: " << m_quantityNeeded << endl;
			os << "Quantity Available: " << m_quantityOnHand<< endl;
			os << "Unit Price: $" << fixed << setprecision(2) << m_price << endl;
			os << "Needed Purchase Fund: $" << fixed << setprecision(2) << m_price * (m_quantityNeeded - m_quantityOnHand) << endl;
		}
		else {
			if (strlen(m_description) > 35) {
				strncpy(str, m_description, 35);
			}
			os << m_skuNum << " | " << left << setw(35);
			if (strlen(m_description) <= 35) {
				os << m_description;
			}
			else {
				os << str;
			}
			os << " | " << right << setw(4) << m_quantityOnHand<< " | " << right << setw(4) << m_quantityNeeded << " | " << right << setw(7) << m_price << " |";
		}
        return os;
    }
    std::istream& Item::read(std::istream& is)
    {
        char description[35];
        delete[] m_description;
        m_state.clear();
        cout << "AMA Item:" << endl;
        cout << "SKU: " << m_skuNum << endl;
        cout << "Description: ";
        is >> description;

        m_description = new char[strlen(description) + 1];
        strcpy(m_description, description);
        m_quantityNeeded = ut.getInt(1, 9999, "Quantity Needed: ");
        m_quantityOnHand= ut.getInt(0, m_quantityNeeded, "Quantity On Hand: ");
        cout << "Unit Price: $";
        m_price = ut.getdouble(is, 0.0, 9999.0);

        return is;
    }
    void Item::clear()
    {
        m_price = 0.0;
        m_quantityOnHand= 0;
        m_quantityNeeded = 0;
        m_state = "This object is in a good state!";
    }
    Item::~Item()
    {
        delete[] m_description;
        m_description = nullptr;
    }
}


