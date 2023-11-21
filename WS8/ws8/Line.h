#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include "LblShape.h"

namespace sdds {
	class Line : public LblShape {
		int m_length;
	public:
		Line();
		Line(const char* s, const int length);
		void getSpecs(istream& is);
		void draw(ostream& os) const;
	};
}
#endif