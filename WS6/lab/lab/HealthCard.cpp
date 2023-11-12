#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "HealthCard.h"
using namespace std;
namespace sdds {

	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {
		if (name != nullptr) {		
			if (number < 9999999999 && number > 999999999) {
				if (strlen(vCode) == 2) {
					if (strlen(sNumber) == 9) {
						return true;
					}
				}
			}
		}
		return false;
	}
	void HealthCard::setEmpty() {
		delete[] m_name;
		m_name = nullptr;
		m_number = 0;
		m_vCode[0] = '\0';
		m_sNumber[0] = '\0';
	}
	void HealthCard::allocateAndCopy(const char* name) {
		if (name) {
			delete[] m_name;
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
	}
	void HealthCard::extractChar(istream& istr, char ch) const {
		char next;
		next = istr.peek();

		if (next == ch) {
			istr.ignore();
		} else {
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}		
	}
	std::ostream& HealthCard::printIDInfo(ostream& ostr)const {
		cout<< m_number << "-" << m_vCode << ", " << m_sNumber;
		return ostr;
	}
	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {
		if (validID(name, number, vCode, sNumber)) {
			allocateAndCopy(name);
			m_number = number;
			strcpy(m_vCode, vCode);
			strcpy(m_sNumber, sNumber);
		}
		else {
			setEmpty();
		}

	}
	HealthCard::HealthCard() {
		setEmpty();

	}
	HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
		set(name, number, vCode, sNumber);
	}

	HealthCard::HealthCard(const HealthCard& hc) {
		if (validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)) {
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_vCode);
		}
		else {
			setEmpty();
		}
	}
	HealthCard& HealthCard::operator=(const HealthCard& hc) {
		if (&hc != this) {
			if (hc.validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)) { 
				set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
			}
			else {
				setEmpty();
			}
		}
		return *this;
	}
	HealthCard::~HealthCard() {
		delete[] m_name;
	}
	HealthCard::operator bool() const {
		if (m_name != nullptr) {
			return true;
		}
		return false;
	}
	std::ostream& HealthCard::print(std::ostream& ostr, bool toFile) const {
		if (*this) {
			if (toFile) {
				ostr << m_name << "," << m_number << "-" << m_vCode << ", " << m_sNumber << endl;
			} else {
				ostr.width(50);
				ostr.fill('.');
				ostr.setf(ios::left);
				cout<< m_name;
				printIDInfo(ostr);
			}	
		}
		return ostr;
	}
	std::istream& HealthCard::read(std::istream& istr) {
		char l_name[MaxNameLength];
		long long l_number;
		char l_vCode[3];
		char l_sNumber[10];

		istr.get(l_name, MaxNameLength, ',');
		extractChar(istr, ',');

		istr >> l_number;
		extractChar(istr, '-');

		istr.get(l_vCode, 4, ',');
		extractChar(istr, ',');

		istr.get(l_sNumber, 11, '\n');

		if (!istr.fail()) { 
			set(l_name, l_number, l_vCode, l_sNumber);
		}

		istr.clear();
		istr.ignore(1000, '\n'); 

		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc) {
		if (hc) {
			hc.print(ostr, false);
		}
		else {
			cout<< "Invalid Health Card Record";
		}
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, HealthCard& hc) {
		return hc.read(istr);
	}
}
