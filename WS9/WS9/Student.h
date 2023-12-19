#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

namespace sdds {
	class Student {
		char* m_name;
		int m_age;
	public:
		Student();
		Student(const Student& s);
		Student(const char* name, const int age);
		Student& operator=(const Student& s);
		virtual void display() const;
		virtual ~Student();
	};
}
#endif