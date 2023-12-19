#include "iProduct.h"

namespace sdds
{
	std::istream& operator>>(std::istream& istr, iProduct& iProduct)
	{
		iProduct.read(istr);
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const iProduct& iProduct)
	{
		iProduct.display(ostr);
		return ostr;
	}
}