#define _CRT_SECURE_NO_WARNINGS
#include "AidMan.h"
#include "Date.h"

using namespace std;

namespace sdds {

	AidMan::AidMan(const char* filen) : fileName(nullptr), m("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database") {
		fileName = nullptr;
		if (filen != nullptr) {
			fileName = new char[strlen(filen) + 1];
			strcpy(fileName, filen);
		}
	}
	AidMan::~AidMan() {
		delete[] fileName;
		fileName = nullptr;
	}
	void AidMan::run() {
		int i = 1;

		while (i != 0) {
			i = menu();
			switch (i) {
			case 0:
				std::cout << "Exiting Program!" << std::endl;
				break;
			case 1:
				std::cout << "\n****List Items****\n\n";
				break;
			case 2:
				std::cout << "\n****Add Item****\n\n";
				break;
			case 3:
				std::cout << "\n****Remove Item****\n\n";
				break;
			case 4:
				std::cout << "\n****Update Quantity****\n\n";
				break;
			case 5:
				std::cout << "\n****Sort****\n\n";
				break;
			case 6:
				std::cout << "\n****Ship Items****\n\n";
				break;
			case 7:
				std::cout << "\n****New/Open Aid Database****\n\n";
				break;
			}
		}
	}
	unsigned int AidMan::menu()
	{
		cout << "Aid Management System" << endl;
		cout << "Date: 2023/12/09" << endl;
		cout << "Data file: ";
		if (fileName == nullptr) {
			cout << "No file" << endl;
		}
		else {
			cout << fileName << endl;
		}
		cout << endl;
		return m.run();
	}
}