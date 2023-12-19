#define _CRT_SECURE_NO_WARNINGS
#include "Graduate.h"
using namespace std;

namespace sdds {
	Graduate::Graduate()
	{
		m_supervisor = nullptr;
		m_thesis = nullptr;
	}
	Graduate::Graduate(const Graduate& g) : Student(g), m_supervisor(nullptr), m_thesis(nullptr)
	{
		m_thesis = new char[strlen(g.m_thesis) + 1];
		strcpy(m_thesis, g.m_thesis);

		m_supervisor = new char[strlen(g.m_supervisor) + 1];
		strcpy(m_supervisor, g.m_supervisor);
	}
	Graduate::Graduate(const char* name, int age, const char* thesis, const char* supervisor)
		: Student (name, age), m_supervisor(nullptr), m_thesis(nullptr)
	{
		m_thesis = new char[strlen(thesis) + 1];
		strcpy(m_thesis, thesis);

		m_supervisor = new char[strlen(supervisor) + 1];
		strcpy(m_supervisor, supervisor);
	}
	Graduate& Graduate::operator=(const Graduate& g)
	{
		if (this != &g) {
			Student::operator=(g);
			delete[] m_thesis;
			delete[] m_supervisor;

			m_thesis = new char[strlen(g.m_thesis) + 1];
			strcpy(m_thesis, g.m_thesis);

			m_supervisor = new char[strlen(g.m_supervisor) + 1];
			strcpy(m_supervisor, g.m_supervisor);
		}
		return *this;
	}
	Graduate::~Graduate()
	{
		delete[] m_supervisor;
		delete[] m_thesis;
	}
	void Graduate::display() const
	{
		Student::display();
		cout << "Thesis Title: " << m_thesis << endl;
		cout << "Supervisor: " << m_supervisor << endl;
		cout << "---------------------------------------------" << endl;
	}
}