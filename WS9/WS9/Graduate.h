#ifndef SDDS_GRADUATE_H
#define SDDS_GRADUATE_H

#include "Graduate.h"
#include "Student.h"
#include <cstring>

using namespace std;

namespace sdds {
	class Graduate : public Student {
		char* m_supervisor;
		char* m_thesis;
	public:
		Graduate();
		Graduate(const Graduate& g);
		Graduate(const char* name, int age, const char* thesis, const char* supervisor);
		Graduate& operator=(const Graduate& g);
		void display() const override;
		~Graduate() override;
	};
}
#endif