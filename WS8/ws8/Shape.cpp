#define _CRT_SECURE_NO_WARNINGS
#include "Shape.h"

using namespace std;

namespace sdds {
	ostream& operator<<(ostream& ostr, const Shape& shape)
	{
		shape.draw(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, Shape& shape)
	{
		shape.getSpecs(istr);
		return istr;
	}
}