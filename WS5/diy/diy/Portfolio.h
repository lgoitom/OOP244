/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_

#include <iostream>

namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;

   public:
       Portfolio();
       void emptyPortfolio();
       Portfolio(double value, const char* stock, char type);
       void dispPortfolio() const;
       std::ostream& display() const;
       operator double() const;
       operator const char* () const;
       operator char() const;
       operator bool() const;
       Portfolio& operator+=(double value);
       Portfolio& operator-=(double value);
       bool operator~() const;
       Portfolio& operator<<(Portfolio& movingLeft);
       Portfolio& operator>>(Portfolio& movingRight);
   };

   double operator +(const Portfolio&, const Portfolio&);
   double operator +=(double&, const Portfolio&);

}
#endif // SDDS_Portfolio_H_