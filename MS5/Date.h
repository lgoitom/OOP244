#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include"Status.h"
#include "Utils.h"
namespace sdds {


	class Date {
		const int maxYear = 2030;

		sdds::Status m_state{};
		sdds::Utils ut;

		int year = 2023;
		int month = 12;
		int day = 9;

		bool m_formatted{ true };


		bool validDate();
		bool validDateWithParameters(int year, int month, int day);
		int uniqueValue() const;
	public:
		Date() {}
		Date(int year, int month, int day);
		bool operator =(const Date& other);
		bool operator ==(const Date& other) const;
		bool operator !=(const Date& other) const;
		bool operator <(const Date& other) const;
		bool operator >(const Date& other) const;
		bool operator <=(const Date& other) const;
		bool operator >=(const Date& other) const;
		const sdds::Status& state() const;
		Date& formatted(bool isFormatted);
		operator bool() const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& is);
		int getYear() const { return year; }
		int getMonth() const { return month; }
		int getDay() const { return day; }
	};
	std::ostream& operator<<(std::ostream& os, const Date& date);
	std::istream& operator>>(std::istream& is, Date& date);
}
#endif // !DATE_H