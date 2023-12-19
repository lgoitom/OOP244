#include <iostream>
#include <cstring>
#include "iProduct.h"

using namespace std;
namespace sdds {
	iProduct::~iProduct() {
	}

	ostream& operator<<(ostream& ostr, const iProduct& obj) {
		obj.display(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, iProduct& obj) {
		obj.read(istr);
		return istr;
	}
}