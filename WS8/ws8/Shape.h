#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
	class Shape {
	public:
		virtual void draw(ostream& os) const= 0;
		virtual void getSpecs(istream& is) = 0;
		virtual ~Shape() {};
	};
	ostream& operator<<(ostream& ostr, const Shape& shape);
	istream& operator>>(istream& istr, Shape& shape);
}
#endif