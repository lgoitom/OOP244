#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"

using namespace std;

namespace sdds {
	Menu::Menu(const char* s) {
		if (s != nullptr || strlen(s) != 0) {
			list = new char[strlen(s) + 1];
			strcpy(list, s);

			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i + 1] == '\0') {
					options++;
				} else if (s[i] == '\t') {
					options++;
				}
			}
			if (options > OPTION_MAX) {
				delete[] list;
				list = nullptr;
			}
		} else {
			list = nullptr;
		}
	}
	Menu::~Menu()
	{
		delete[] list;
		list = nullptr;
	}
	unsigned int Menu::run() const
	{
		bool loop = false;
		unsigned int input;
		if (list != nullptr) {
			get();
			cout << "> ";
			while (!loop) {
				cin >> input;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Invalid Integer, retry: ";
				}
				else if (input < 1 || input > options) {
					if (input == 0) {
						return input;
					}
					cout << "Value out of range [0<=val<=" << options << "]: ";
				}
				else {
					loop = true;
				}
			}
			return input;
		}
		else {
			cout << "Invalid Menu!" << endl;
			return 0;
		}
	}
	void Menu::get() const
	{
		int i = 0;
		unsigned int j = 1;
		do {
			do {
				if (list[i] == '\t') {
					j++;
					cout << '\n';
					cout << j << "- ";
				}
				else {
					if (i == 0) {
						cout << j << "- ";
					}
					cout << list[i];
				}
				i++;
			} while (list[i] != '\0');
		} while (j < options);
		cout << "\n---------------------------------" << endl;
		cout << "0- Exit" << endl;
	}
}