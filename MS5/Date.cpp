#include <iomanip>
#include "Date.h"

namespace sdds {
	bool Date::validDate() {
		bool result = true ;

		if (year < 2023 || year > maxYear)
		{
			m_state = "Invalid year in date";
			m_state.setStatus(1);
			result = false;
		}
		if (month < 1 || month > 12)
		{
			m_state = "Invalid month in date";
			m_state.setStatus(2);
			result = false;
		}
		if (day < 1 || day > ut.daysOfMon(month, year)) {
			m_state = "Invalid day in date";
			m_state.setStatus(3);
			result = false;
		}

		return result;
	}
	bool Date::validDateWithParameters(int year, int month, int day)
	{
		if (year < 2023 || year> maxYear)
		{
			m_state = "Invalid year in date";
			m_state.setStatus(1);
			return false;
		}
		if (month < 1 || month > 12)
		{
			m_state = "Invalid month in date";
			m_state.setStatus(2);
			return false;
		}
		if (day < 1 || day > ut.daysOfMon(month, year)) {
			m_state = "Invalid day in date";
			m_state.setStatus(3);
			return false;
		}
		return true;
	}
	int Date::uniqueValue() const
	{
		return year * 372 + month * 31 + day;
	}
	Date::Date(int f_year, int f_month, int f_day)
	{
		if (validDateWithParameters(f_year, f_month, f_day))
		{
			year = f_year;
			month = f_month;
			day = f_day;
		}

	}
	bool Date::operator=(const Date& other)
	{
		if (this != &other) {
			year = other.year;
			month = other.month;
			day = other.day;
			m_formatted = other.m_formatted;
			m_state = other.m_state;
		}
		return *this;
	}
	bool Date::operator==(const Date& other) const
	{
		return uniqueValue() == other.uniqueValue();
	}
	bool Date::operator!=(const Date& other) const
	{
		return uniqueValue() != other.uniqueValue();
	}
	bool Date::operator<(const Date& other) const
	{
		return uniqueValue() < other.uniqueValue();
	}
	bool Date::operator>(const Date& other) const
	{
		return uniqueValue() > other.uniqueValue();
	}
	bool Date::operator<=(const Date& other) const
	{
		return uniqueValue() <= other.uniqueValue();
	}
	bool Date::operator>=(const Date& other) const
	{
		return uniqueValue() >= other.uniqueValue();
	}
	const sdds::Status& Date::state() const
	{
		return m_state;
	}
	Date& Date::formatted(bool isFormatted)
	{
		m_formatted = isFormatted;
		return *this;
	}
	Date::operator bool() const
	{
		return m_state;
	}
	std::ostream& Date::write(std::ostream& os) const
	{
		if (m_formatted == true) {
			os << year;
			os << "/";
			os.width(2);
			os.fill('0');
			os << month;
			os << "/";
			os.width(2);
			os.fill('0');
			os << day;
		}
		else {
			os << year - 2000;
			os.width(2);
			os.fill('0');
			os << month;
			os.width(2);
			os.fill('0');
			os << day;
		}
		os.fill(' ');

		return os;
	}

	std::istream& Date::read(std::istream& is)
	{
		int receivedDate{};
		is >> receivedDate;

		if (receivedDate >= 1000 && receivedDate <= 9999)
		{
			year = (receivedDate / 10000) + 2000;
			month = (receivedDate / 100) % 1000;
			day = receivedDate % 100;
		}
		else if (receivedDate >= 100000 && receivedDate <= 999999)
		{
			year = receivedDate / 10000;
			month = (receivedDate / 100) % 100;
			day = receivedDate % 100;
			year += 2000;
		}
		if (receivedDate < 100)
		{
			year = 2023;
			month = 0;
			day = receivedDate % 100;
		}


		if (!validDate())
			is.setstate(std::ios::badbit);

		return is;
	}


	std::ostream& operator<<(std::ostream& os, const Date& date)
	{
		return date.write(os);
	}
	std::istream& operator>>(std::istream& is, Date& date)
	{
		return date.read(is);
	}
}


