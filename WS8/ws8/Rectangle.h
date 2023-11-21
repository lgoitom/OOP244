#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include <iostream>
#include <string.h>
#include <cstdio>
#include <iomanip>
#include "Line.h"
#include "LblShape.h"

using namespace std;
namespace sdds {
	class Rectangle : public LblShape {
		int m_width, m_height;
	public:
		Rectangle();
		Rectangle(const char* l, int width, int height);
		void getSpecs(istream& is);
		void draw(ostream& os) const;
	};
}
#endif