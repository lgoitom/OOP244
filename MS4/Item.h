#ifndef ITEM_H
#define ITEM_H
#include "Status.h"
#include "iProduct.h"

using namespace std;
namespace sdds {
	class Item : public iProduct {
	public:
		double m_price;
		int m_qty;
		int m_qtyNeeded;
		char* m_description;
		bool m_linear;
	protected:
		Status m_state;
		int m_sku;
		bool isLinear();
	public:
		Item();
		~Item();
		Item(const Item&);
		Item& operator=(const Item&);
		operator double()const;
		operator bool()const;
		int qtyNeeded()const;
		int qty()const;
		int operator-=(int qty);
		int operator+=(int qty);
		void linear(bool isLinear);
		void clear();
		bool operator==(int sku)const;
		bool operator==(const char* description)const;
		ofstream& save(ofstream& ofstr)const;
		ifstream& load(ifstream& ifstr);
		ostream& display(ostream& ostr)const;
		istream& read(istream& istr);
		int readSku(istream& istr);
	};
}

#endif