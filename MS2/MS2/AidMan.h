#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H

#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Date.h"
#include "Utils.h"

namespace sdds {
	class AidMan {
		char* fileName;
		Menu m;
		unsigned int menu();
	public:
		AidMan(const char* filen = nullptr);
		~AidMan();
		void run();
	};
}
#endif