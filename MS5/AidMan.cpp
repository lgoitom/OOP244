#define _CRT_SECURE_NO_WARNINGS
#include "AidMan.h"
#include "Perishable.h"
#include<iostream>
#include<cstring>
#include<fstream>
#include<limits>
using namespace std;
namespace sdds {

	AidMan::AidMan(const char* filen) : fileName(nullptr), mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database"), m_date(Date()) {
		fileName = nullptr;
		if (filen != nullptr) {
			fileName = new char[strlen(filen) + 1];
			strcpy(fileName, filen);
		}
	}

	void AidMan::run() {
		unsigned int i{};
		ifstream ifstr;

		do {
			i = menu();
			if ((i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6) && (fileName == nullptr)) {
				i = 7; 
			}
			switch (i) { 
			case 0:
				std::cout << "Exiting Program!\n"; 
				break;
			case 1:

				std::cout << "\n****List Items****\n";
				list();
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
				std::cout << "\n****New/Open Aid Database****\n";
				load("data.dat");
				break;
			default:
				std::cout << "Invalid option!\n\n"; 
				break;
			}

		} while (i != 0);
		ifstr.close();
	}
	unsigned int AidMan::menu() const
	{

		cout << "Aid Management System" << endl;
		cout << "Date: " << m_date << endl;
		cout << "Data file: ";
		if (fileName == nullptr) {
			cout << "No file" << endl;
		}
		else {
			cout << fileName << endl;
		}
		cout << "---------------------------------" << endl;
		return mainMenu.run();
	}
	void AidMan::save()
	{
		ofstream outfile(fileName);

		if (!outfile.is_open()) {
			cout << "Failed to open " << fileName << " for writing!" << endl;
			return;
		}

		for (int i = 0; i < noOfRecs; ++i) {
			if (Product[i]) {
				Product[i]->save(outfile);
				outfile << '\n';
			}
		}

		outfile.close();
	}

	bool AidMan::load(const char* filename)
	{
		if (filename == nullptr || filename[0] == '\0') {
			return false;
		}

		delete[] fileName;
		fileName = nullptr;
		fileName = new char[strlen(filename) + 1];
		strcpy(fileName, filename);
		ifstream ifstr(filename);
		if (!ifstr.is_open())
		{
			int i = 0;
			cout << "Failed to open" << filename << "for reading!" << endl;
			cout << "Would you like to create a new data file?" << endl;
			cout << "1- Yes!" << endl;
			cout << "0- Exit" << endl;
			cin >> i;
			if (i == 1) {
				ofstream outfile(fileName);
				if (outfile.is_open()) {
					outfile.close();
				}
				else {
					cout << "Failed to create new data file!" << endl;
					return false;
				}
			}
			return false;
		}

		noOfRecs = 0;

		while (!ifstr.eof() && noOfRecs < sdds_max_num_items)
		{
			if (ifstr.peek() >= '1' && ifstr.peek() <= '3')
			{
				Product[noOfRecs] = new Perishable;
			}
			else if (ifstr.peek() >= '4' && ifstr.peek() <= '9')
			{
				Product[noOfRecs] = new Item;
			}
			else
			{
				ifstr.clear();
				ifstr.ignore(1000, '\n');
				continue;
			}

			Product[noOfRecs]->load(ifstr);

			if (*Product[noOfRecs])
			{
				noOfRecs++;
			}
		}
		if (*this)
		{
			cout << "Enter file name: " << fileName << endl;
			cout << noOfRecs << " records loaded!\n" << endl;

		}
		save();
		return (noOfRecs > 0);
	}


	int AidMan::list(const char* sub_desc) const
	{

		int rowNum = 0;
		int number = 0;
		bool validInput = true;

		cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

		for (int i = 0; i < noOfRecs; i++) {

			if (sub_desc) {

				cout << "   " << i + 1 << " | ";
				Product[i]->display(cout);
				rowNum++;
				cout << endl;
			}
			else if (sub_desc == nullptr)
			{
				Product[i]->linear(true);
				cout << "   " << i + 1 << " | ";
				Product[i]->display(cout);
				rowNum++;
				cout << endl;
			}
		}

		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

		do {
			cout << "Enter row number to display details or <ENTER> to continue:" << endl;
			cout << "> ";
			cin.ignore();

			if (cin.peek() == '\n') {
				cout << "\n";
				break;
			}

			cin >> number;

			if (number >= 1 && number <= rowNum) {
				Product[number - 1]->linear(false);
				Product[number - 1]->display(cout);
				cout << endl << endl;
			}
			else {
				cout << "Invalid input. Please enter a valid row number." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			cin.get();
		} while (!validInput);

		return rowNum;

	}

	AidMan::operator bool() const
	{
		return fileName && noOfRecs;
	}

	void AidMan::deallocate()
	{
		for (size_t i = noOfRecs; i > 0;)
		{
			--i;
			delete Product[i];
			Product[i] = nullptr;
		}
		noOfRecs = 0;
	}


	AidMan::~AidMan()
	{
		delete[] fileName;
		fileName = nullptr;
		deallocate();

	}



}
