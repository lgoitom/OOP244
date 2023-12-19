#include "iProduct.h"

using namespace std;
namespace sdds {
	iProduct::~iProduct()
	{
	}
	ostream& operator<<(ostream& ostr, iProduct& p) {
		p.display(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, iProduct& p) {
		p.read(istr);
		return istr;
	}
}