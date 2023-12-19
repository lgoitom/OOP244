#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Status.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
	Status::Status(const char* description)
	{
		if (description){
			ut.alocpy(m_description, description);
		}
		else{
			m_description = nullptr;
		}
		m_code = 0;

	}

	Status& Status::operator=(int code)
	{
		m_code = code;
		return *this;
	}

	Status& Status::operator=(const char* description)
	{
		if (description) {
			delete[] m_description;
			m_description = new char[strlen(description) + 1];
			strcpy(m_description, description);
		}
		return *this;
	}

	Status::operator int() const
	{
		return m_code;
	}

	Status::operator const char* () const
	{
		return m_description;
	}

	Status::operator bool() const
	{
		return m_description == nullptr;
	}

	Status& Status::clear()
	{
		if (m_description != nullptr)
		{
			delete[] m_description;
			m_description = nullptr;
			m_code = 0;
		}

		return *this;
	}

	std::ostream& Status::print(std::ostream& ostr) const
	{
		if (m_code != 0) {
			ostr << "ERR#" << m_code << ":";
			ostr << " " << m_description;

		}
		else {
			ostr << m_description;
		}

		return ostr;
	}

	std::ostream& operator << (std::ostream& ostr, const Status& sts)
	{
		return sts.print(ostr);
	}
}