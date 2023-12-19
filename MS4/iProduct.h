#ifndef IPRODUCT_H
#define IPRODUCT_H
#include <iostream>

using namespace std;
namespace sdds {
	class iProduct {
	public:
		virtual ~iProduct();
		virtual int readSku(istream& istr) = 0;
		virtual int operator-=(int qty) = 0;
		virtual int operator+=(int qty) = 0;
		virtual operator double()const = 0;
		virtual operator bool()const = 0;
		virtual int qtyNeeded()const = 0;
		virtual int qty()const = 0;
		virtual void linear(bool isLinear) = 0;
		virtual ofstream& save(ofstream& ofstr)const = 0;
		virtual ifstream& load(ifstream& ifstr) = 0;
		virtual ostream& display(ostream& ostr)const = 0;
		virtual istream& read(istream& istr) = 0;
		virtual bool operator==(int sku)const = 0;
		virtual bool operator==(const char* description)const = 0;
	};
	ostream& operator<<(ostream& ostr, const iProduct& obj);
	istream& operator>>(istream& istr, iProduct& obj);
}

#endif