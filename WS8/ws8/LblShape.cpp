#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"

using namespace std;
namespace sdds {
	const char* LblShape::label() const
	{
		return m_label;
	}
	LblShape::LblShape()
	{
		if (this->m_label != nullptr) {
			m_label = nullptr;
		}
	}
	LblShape::LblShape(const char* label)
	{
		if (label != nullptr) {
			this->m_label = new char[strlen(label) + 1];
			strcpy(this->m_label, label);
		}

	}
	LblShape::~LblShape()
	{
		delete[] m_label;
		m_label = nullptr;
	}
	void LblShape::getSpecs(istream& is)
	{
		char buffer[100];
		is.get(buffer, 100, ',');
		is.ignore();
		
		delete[] this->m_label;
		m_label = new char[strlen(buffer) + 1];
		strcpy(m_label, buffer);
	}
}