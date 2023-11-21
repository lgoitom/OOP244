#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Date.h"
#include "Utils.h"
using namespace std;
namespace sdds {

    bool Date::validate() {

        int currentYear;
        ut.getSystemDate(&currentYear);
        stat.clear();

        if (mYear < currentYear || mYear > maxValue) {
            stat = "Invalid year in date";
            stat = 1;
        }
        else if (mMonth < 1 || mMonth > 12) {
            stat = "Invalid month in date";
            stat = 2;
        }
        else if (mDay < 1 || mDay > ut.daysOfMon(mMonth, mYear)) {
            stat = "Invalid day in date";
            stat = 3;
        } else {
            return true;
        }
        return false;
    }


    int Date::unique() const {
		int year = mYear * 372 + mMonth * 31 + mDay;
		return year;
    }
    Date::operator bool() const {
        return stat;
    }

    Date::Date() {
        int currentYear;
        ut.getSystemDate(&currentYear, &mMonth, &mDay);
        mYear = currentYear;
        invalid = false;
        format = true;
    }


    Date::Date(int y, int m, int d) {
        mYear = y;
        mMonth = m;
        mDay = d;
        invalid = false;
        format = true;
        validate();
    }


    bool Date::operator==(const Date& getDate) const {
        if( this->unique() == getDate.unique()){
			return true;
		}
		return false;
    }

    bool Date::operator!=(const Date& getDate) const {
        if( this->unique() != getDate.unique()){
			return true;
		}
		return false;
    }

    bool Date::operator>=(const Date& getDate) const {
        if( this->unique() >= getDate.unique()){
			return true;
		}
		return false;
    }

    bool Date::operator<=(const Date& getDate) const {
        if( this->unique() <= getDate.unique()){
			return true;
		}
		return false;
    }

    bool Date::operator<(const Date& getDate) const {
        if( this->unique() < getDate.unique()){
			return true;
		}
		return false;
	}

    bool Date::operator>(const Date& getDate) const {
        if( this->unique() > getDate.unique()){
			return true;
		}    
		return false;
	}
    const Status& Date::state() {
        return stat;
    }
    Date& Date::formatted(bool split) {
        format = split;
        return *this;
    }

    bool notint(bool c) {
        return c == true;
    }
    std::ostream& Date::write(std::ostream& ostr) const {
        if (format == true) {
            ostr << mYear << "/" << setfill('0') << setw(2) << mMonth << "/" << setfill('0') << setw(2) << this->mDay;
        } else if (format == false) {
            ostr << mYear - (mYear / 100) * 100 << setfill('0') << setw(2) << mMonth << setfill('0') << setw(2) << mDay;
        }

        return ostr;
    }

	istream& Date::read(istream& istr) {

		int date, y, m, d;
		cin >> date;

		if (!date){
			stat = 0;
			stat = "Invalid date value";
			istr.setstate(ios::badbit);
		}
		else if (date > 9 && date < 100) {
			stat = 2;
			stat = "Invalid month in date";
			istr.setstate(ios::badbit);
		}
		else if (date > 999 && date < 10000){
			m = date / 100;
			d = date - m * 100;
			mYear = 2023;
			mMonth = m;
			mDay = d;
			if (!validate()) {
				istr.setstate(ios::badbit);
			}
		}
		else if (date > 99999 && date < 1000000){
			y = date / 10000;
			m = (date - y * 10000) / 100;
			d = date - y * 10000 - m * 100;
			mYear = y + 2000;
			mMonth = m;
			mDay = d;
			if (!validate()){
				istr.setstate(ios::badbit);
			}
		}
		else{
			istr.setstate(ios::badbit);
		}

		return istr;
	}

    std::ostream& operator<<(std::ostream& os, const Date& dat) {
        return dat.write(os);
    }

    std::istream& operator>>(std::istream& is, Date& dat) {
        return dat.read(is);
    }
}