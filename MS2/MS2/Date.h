#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include<cstring>
#include<sstream>
#include"Status.h"
namespace sdds {

    const int maxValue = 2030;
    class Date
    {
        Status stat;
        bool format;
        bool invalid;
        int mYear;
        int mMonth;
        int mDay;
        bool validate();
        int unique() const;
    public:
        Date();
        Date(int y, int m, int d);
        bool notint(bool c = false);
        const Status& state();
        Date& formatted(bool split);
        bool operator==(const Date& getDate) const;
        bool operator!=(const Date& getDate) const;
        bool operator>=(const Date& getDate) const;
        bool operator<=(const Date& getDate) const;
        bool operator<(const Date& getDate) const;
        bool operator>(const Date& getDate) const;
        operator bool() const;
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& os) const;
    };
    std::ostream& operator<<(std::ostream& os, const Date& dat);
    std::istream& operator>>(std::istream& is, Date& dat);
}
#endif
