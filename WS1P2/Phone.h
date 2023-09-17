// runs the phone directory application

#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <cstring>
#include <string.h>

namespace sdds {
	struct Person {
		char name[51];
		char areaCode[50];
		char prefix[50];
		char number[50];
	};

	// runs the phone directory application
	void phoneDir(const char* programTitle, const char* fileName);
	//void reader(const char* fileName, struct Person);
	void lower(char* str);
	int check(const char* s1, const char* s2);
	int readFile(const char* fileName, Person* p, char ch[][100], int maxRecords);
	int caseCheck(const char* list, const char* input);



}

#endif