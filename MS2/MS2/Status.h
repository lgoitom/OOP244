#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H

#include <cstring>
#include <iostream>

namespace sdds {
	class Status {
		char* description;
		int code;

	public:
		Status(const char* getDesc = nullptr);
		Status(const Status& other);
		operator int() const;
		operator const char* () const;
		operator bool() const;
		Status& operator=(const char* other2);
		Status& operator=(int code);
		Status& clear();
		~Status();
		std::ostream& print(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Status& get);
}

#endif