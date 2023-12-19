#define _CRT_SECURE_NO_WARNINGS
#include "Perishable.h"
#include"Date.h"
#include<iostream>
#include <limits>
#include<iomanip>
#include<cstring>
#include<fstream>
using namespace std;
namespace sdds {
	Perishable::Perishable() {}
	Perishable::Perishable(const Perishable& other) :Item(other)
	{
		*this = other;
	}
	Perishable& Perishable::operator=(const Perishable& perishable)
	{
		if (this != &perishable) {
			(Item&)*this = perishable;

			delete[] m_instructions;

			if (perishable.m_instructions != nullptr) {
				m_instructions = new char[strlen(perishable.m_instructions) + 1];
				strcpy(m_instructions, perishable.m_instructions);
			}
			else {
				m_instructions = nullptr;
			}

			m_expiry = perishable.m_expiry;
		}

		return *this;
	}
	const Date& Perishable::expiry() const
	{
		return m_expiry;
	}
	void Perishable::setUnformatted()
	{
		m_expiry.formatted(false);
	}

	char* Perishable::readInstructions(istream& istr)
	{
		delete[] m_instructions;
		m_instructions = nullptr;
		char tempInstructions[1000];
		tempInstructions[0] = '\0';
		istr.get(tempInstructions, 1000, '\n');
		ut.alocpy(m_instructions, tempInstructions);


		return m_instructions;
	}

	ostream& Perishable::displayExpiryDate(ostream& ostr) const
	{
		m_expiry.write(ostr);
		return ostr;
	}
	istream& Perishable::readExpiryDate(istream& istr)
	{
		if (istr)
		{
			cout << "Expiry date (YYMMDD): ";
			istr.clear();
			istr.ignore();
			m_expiry.read(istr);
		}
		return istr;
	}
	int Perishable::readSku(istream& istr)
	{
		m_sku = ut.getint(10000, 39999, "SKU: ");
		return m_sku;
	}
	ofstream& Perishable::save(ofstream& ofstr) const
	{
		if (!ofstr.fail()) {
			Item::save(ofstr);
			ofstr << '\t' << (m_instructions ? m_instructions : "") << '\t';
			Date temp(m_expiry.getYear(), m_expiry.getMonth(), m_expiry.getDay());
			temp.formatted(false);
			ofstr << temp;
		}
		return ofstr;
	}
	ifstream& Perishable::load(ifstream& ifstr)
	{

		Item::load(ifstr);
		ifstr.ignore();

		char tempInstructions[1000];
		tempInstructions[0] = '\0';

		ifstr.getline(tempInstructions, 1000, '\t');
		if (tempInstructions[0] != '\0') {
			ut.alocpy(m_instructions, tempInstructions);
		}
		else
		{
			delete[] m_instructions;
			m_instructions = nullptr;
		}


		ifstr >> m_expiry;
		ifstr.ignore();
		if (ifstr.fail())
		{
			status.clear();
			status.setStatus("Input file stream read (perishable) failed!");
		}
		return ifstr;
	}
	ostream& Perishable::display(ostream& ostr) const
	{
		if (m_expiry)
		{
			if (Item::linear())
			{
				Item::display(ostr);
				ostr << (m_instructions && m_instructions[0] != '\0' ? '*' : ' ');
				m_expiry.write(ostr);
			}
			else {
				ostr << "Perishable ";
				Item::display(ostr);
				ostr << "Expiry date: ";
				ostr << m_expiry << endl;
				if (m_instructions != nullptr && m_instructions[0] != '\0') {
					ostr << "Handling Instructions: " << m_instructions << endl;
				}
			}
		}
		else { ostr << "Bad state"; }

		return ostr;
	}
	istream& Perishable::read(std::istream& istr)
	{

		char temp[500];

		Item::read(istr);
		delete[] m_instructions;
		m_instructions = nullptr;

		istr.ignore();
		cout << "Expiry date (YYMMDD): ";
		istr >> m_expiry;
		cout << "Handling Instructions, ENTER to skip: ";
		istr.get(temp, 500, '\n');
		if (temp[0] != '\0') {
			if (temp != nullptr) {
				ut.alocpy(m_instructions, temp);
			}
		}
		if (!istr) {
			status.clear();
			status.setStatus("Perishable console date entry failed!");
		}
		istr.ignore(2000, '\n');

		return istr;
	}
}