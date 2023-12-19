#ifndef STATUS_H
#define STATUS_H
#include <iostream>

using namespace std;
namespace sdds {
	class Status {
		char* objStatus;
		int statusCode;
	public:
		Status();
		~Status();
		Status(const char* obj);
		Status& operator=(const Status&);
		Status& operator=(int newValue);
		Status& operator=(const char* newStatus);
		operator int() const;
		operator const char* () const;
		operator bool() const;
		Status& clear();
	};
	ostream& operator<<(ostream& os, const Status& obj);
};

#endif