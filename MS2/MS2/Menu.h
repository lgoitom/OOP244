#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#define OPTION_MAX 15

#include <iostream>
#include <cstring>

namespace sdds {
	class Menu {
		unsigned int options = 0;
		char* list{};
	public:
		Menu(const char* s);
		~Menu();
		unsigned int run() const;
		void get() const;
	};
}

#endif