#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include <iostream>
#include <cstring>
#include <cstdio>
#include "Shape.h"

namespace sdds {
	class LblShape : public Shape {
		char* m_label = nullptr;
	protected:
		const char* label() const;
	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		void getSpecs(istream& is);
	};
}
#endif