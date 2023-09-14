// runs the phone directory application

#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H

#include <iostream>

namespace sdds {
	void phoneDir(const char* programTitle, const char* fileName);
	struct Person reader(char input, const char* fileName);
	void compare(struct Person person[], );

	struct Person {
		char name[50];
		int areaCode[50];
		int prefix[50];
		int number[50];
	};

}

#endif