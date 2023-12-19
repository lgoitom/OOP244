#ifndef DATE_H
#define DATE_H
#include "Status.h"

using namespace std;
namespace sdds {
	const int maxYear = 2030;
	class Date {
		int year;
		int month;
		int day;
		Status m_state;
		bool format;
		bool validate();
		int unique() const;
		int stringToInt(char* str);
		bool validDigit(char* str);
	public:
		Date();
		Date(int newYear, int newMonth, int newDay);
		~Date();
		Date(const Date&);
		Date& operator=(const Date&);
		bool operator==(const Date& obj) const;
		bool operator!=(const Date& obj) const;
		bool operator<(const Date& obj) const;
		bool operator>(const Date& obj) const;
		bool operator<=(const Date& obj) const;
		bool operator>=(const Date& obj) const;
		Status& state();
		Date& formatted(bool format);
		operator bool() const;
		ostream& write(ostream& os) const;
		istream& read(istream& is);
	};
	ostream& operator<<(ostream& os, const Date& obj);
	istream& operator>>(istream& is, Date& obj);
};

#endif