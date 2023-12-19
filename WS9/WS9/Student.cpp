#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"

using namespace std;

namespace sdds {
	Student::Student()
	{
		m_name = nullptr;
		m_age = 0;
	}
	Student::Student(const Student& s) : m_age(s.m_age)
	{
		m_name = new char[strlen(s.m_name) + 1];
		strcpy(m_name, s.m_name);
	}
	Student::Student(const char* name, const int age) : m_age(age)
	{
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
		
		m_age = age;
	}
	Student& Student::operator=(const Student& s)
	{
		if (this != &s) {
			delete[] m_name;
			m_name = new char[strlen(s.m_name) + 1];
			strcpy(m_name, s.m_name);
			m_age = s.m_age;
		}
		return *this;
	}
	void Student::display() const
	{
		cout << "Name: " << m_name << endl;
		cout << "Age: " << m_age << endl;
	}
	Student::~Student()
	{
		delete[] m_name;
		m_name = nullptr;
	}
}