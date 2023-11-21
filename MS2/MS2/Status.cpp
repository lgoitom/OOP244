#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Status.h"
#include "Utils.h"

using namespace std;

namespace sdds {

	Status::Status(const char* getDesc){
		if (getDesc) {
			description = new char[strlen(getDesc) + 1];
			strcpy(description, getDesc);
		}
		else {
			description = nullptr;
		}
		code = 0;
	}


	Status::Status(const Status& other) {
		
		description = nullptr;
		if (other.description) {
			description = new char[strlen(other.description) + 1];
			strcpy(description, other.description);
			code = other.code;
		}
		else {
			description = nullptr;
			code = 0;
		}
	}

	Status& Status::operator=(const char* other2) {
		if (other2) {
			delete[] description;
			description = new char[strlen(other2) + 1];
			strcpy(description, other2);
		}
		return *this;
	}

	Status& Status::operator=(int getCode) {
		code = getCode;
		return *this; 
	}

	Status::operator int() const{
		return code;
	}

	Status::operator const char* () const{
		return description;
	}

	Status::operator bool() const{
		return (description == nullptr);
	}

	Status& Status::clear(){
		if (description != nullptr) {
			delete[] description;
			description = nullptr;
			code = 0;
		}
		return *this;

	}
	Status::~Status() {
		delete[] description;
	}
	std::ostream& Status::print(std::ostream& os) const{
		if (code != 0) {
			os<< "ERR#" << code << ":";
			os<< " " << description;

		}
		else {
			os<< description;
		}
		return os;

	}
	std::ostream& operator<<(std::ostream& ostr, const Status& get){
		return get.print(ostr);

	}
}