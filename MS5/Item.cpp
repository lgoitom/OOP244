#define _CRT_SECURE_NO_WARNINGS
#include "Item.h"
#include <iostream>
#include<fstream>
#include<iomanip>
#include <cstring>
#include <limits>
using namespace std;
namespace sdds {
	bool Item::linear() const
	{
		return m_linear;
	}
	Item::Item() {
		m_price = 0;
		m_qty = 0;
		m_qtyNeeded = 0;
		m_description = nullptr;
		m_linear = false;
		m_sku = 0;
		status.clear();
	}
	Item::Item(const Item& obj) {
		if (obj) {
			m_price = obj.m_price;
			m_qty = obj.m_qty;
			m_qtyNeeded = obj.m_qtyNeeded;
			m_linear = obj.m_linear;
			status = obj.status;
			m_sku = obj.m_sku;

			if (obj.m_description != nullptr) {
				m_description = new char[strlen(obj.m_description) + 1];
				for (int i = 0; i < (int)strlen(obj.m_description) + 1; i++)
					m_description[i] = obj.m_description[i];
			}
			else {
				m_description = nullptr;
			}
		}
	}
	Item& Item::operator=(const Item& other)
	{
		if (this != &other)
		{
			m_price = other.m_price;
			m_qty = other.m_qty;
			m_qtyNeeded = other.m_qtyNeeded;
			m_linear = other.m_linear;
			status = other.status;
			m_sku = other.m_sku;

			delete[] m_description;
			if (other.m_description != nullptr)
			{
				m_description = new char[strlen(other.m_description) + 1];
				for (int i = 0; i < (int)strlen(other.m_description) + 1; i++)
					m_description[i] = other.m_description[i];
			}
			else {
				m_description = nullptr;
			}
		}
		return *this;
	}
	int Item::qtyNeeded() const
	{
		return m_qtyNeeded;
	}
	int Item::qty() const
	{
		return m_qty;
	}
	Item::operator double() const
	{
		return m_price;
	}
	Item::operator bool() const {

		return bool(status);
	}
	int Item::readSku(std::istream& istr)
	{
		m_sku = ut.getint(40000, 99999, "SKU: ");
		return m_sku;
	}
	char* Item::readDesc(istream& istr)
	{
		char tempDescription[1000];
		tempDescription[0] = '\0';
		cout << "Description: ";
		istr.ignore(); 
		istr.get(tempDescription, 1000, '\n');
		ut.alocpy(m_description, tempDescription);
		return m_description;
	}

	int Item::readQtyNeeded(istream& istr) {
		int qty_needed;

		while (true) {
			cout << "Quantity Needed: " << flush;
			istr >> qty_needed;

			if (istr.fail() || qty_needed < 1 || qty_needed > 9999) {
				istr.clear();
				istr.ignore(numeric_limits<streamsize>::max(), '\n');
				if (istr.fail())
					cout << "Invalid input. Please enter an integer.\n";
				else
					cout << "Value out of range [1<=val<=9999].\n";
			}
			else {
				break;
			}
		}

		m_qtyNeeded = qty_needed;
		return m_qtyNeeded;
	}

	int Item::readQtyInHand(istream& istr) {
		int qOnHand;

		while (true) {
			cout << "Quantity On Hand: " << flush;
			istr >> qOnHand;

			if (istr.fail() || qOnHand < 0 || qOnHand > m_qtyNeeded) {
				istr.clear();
				istr.ignore(numeric_limits<streamsize>::max(), '\n');
				if (istr.fail())
					cout << "Invalid input. Please enter an integer.\n";
				else
					cout << "Value out of range [1<=val<=9999].\n";
			}
			else {
				break;
			}
		}

		m_qtyNeeded = qOnHand;
		return m_qtyNeeded;
	}

	double Item::readPrice(istream& istr) {
		int neededQty;

		while (true) {
			cout << "Unit Price: $" << flush;
			istr >> neededQty;

			if (istr.fail() || neededQty < 0.0 || neededQty > 9999.00) {
				istr.clear();
				istr.ignore(numeric_limits<streamsize>::max(), '\n');
				if (istr.fail())
					cout << "Invalid number, retry: \n";
				else
					cout << "Value out of range [0.00<=val<=9999.00].\n";
			}
			else {
				break;
			}
		}

		m_qtyNeeded = neededQty;
		return m_qtyNeeded;
	}

	char* Item::FileReadDesc(ifstream& ifstr)
	{
		char tempDescription[1000];
		tempDescription[0] = '\0';
		ifstr.get(tempDescription, 1000, '\t');
		ut.alocpy(m_description, tempDescription);
		return m_description;
	}
	int Item::operator-=(int qty)
	{
		if (*this)
		{
			m_qty -= qty;
		}
		return *this;
	}
	int Item::operator+=(int qty)
	{
		if (*this)
		{
			m_qty += qty;
		}
		return *this;
	}
	void Item::linear(bool isLinear)
	{
		m_linear = isLinear;
	}
	bool Item::operator==(int sku) const
	{
		return sku == m_sku;
	}
	bool Item::operator==(const char* description) const
	{
		if (description == nullptr || m_description == nullptr)
		{
			return false;
		}
		return(strstr(m_description, description) != nullptr);
	}
	ofstream& Item::save(std::ofstream& ofstr) const
	{

		if (this) {
			ofstr.precision(2);
			ofstr.setf(ios::fixed);
			ofstr << m_sku << '\t' << m_description << '\t' << m_qty << '\t' << m_qtyNeeded << '\t' << m_price;
		}

		return ofstr;
	}
	ifstream& Item::load(std::ifstream& ifstr)
	{
		ifstr >> m_sku >> std::ws;
		FileReadDesc(ifstr);
		ifstr >> m_qty;
		ifstr >> m_qtyNeeded;
		ifstr >> m_price;
		if (ifstr.fail())
		{
			status.clear();
			status.setStatus("Input file stream read failed!");
		}
		return ifstr;
	}

	ostream& Item::display(ostream& ostr)const {
		int i;
		double neededAmount = 0.00;

		if (m_description != nullptr) {
			if (linear()) {
				ostr.width(4);
				ostr << m_sku << " | ";
				if (strlen(m_description) > 35) {
					for (i = 0; i < 35; i++) {
						ostr << m_description[i];
					}
					ostr << " | ";
				}
				else {
					ostr.setf(ios::left);
					ostr.width(35);
					ostr << m_description << " | ";
				}
				ostr.unsetf(ios::left);
				ostr.width(4);
				ostr << m_qty << " | ";
				ostr.width(4);
				ostr << m_qtyNeeded << " | ";
				ostr.width(7);
				ostr.precision(2);
				ostr.setf(ios::fixed);
				ostr << m_price << " |";
			}
			else {
				ostr << "AMA Item:" << endl;
				ostr << m_sku << ": " << m_description << endl;
				ostr << "Quantity Needed: " << m_qtyNeeded << endl;
				ostr << "Quantity Available: " << m_qty << endl;
				ostr.precision(2);
				ostr.setf(ios::fixed);
				ostr << "Unit Price: $" << m_price << endl;
				if (m_qtyNeeded > m_qty) {
					neededAmount = (m_qtyNeeded - m_qty) * m_price;
				}
				ostr.precision(2);
				ostr.setf(ios::fixed);
				ostr << "Needed Purchase Fund: $" << neededAmount << endl;
			}
		}
		else {
			ostr << status;
		}

		return ostr;
	}
	istream& Item::read(std::istream& istr)
	{
		if (istr)
		{
			status.clear();
			cout << "AMA Item:" << endl;
			cout << "SKU: " << m_sku << endl;
			readDesc(istr);
			readQtyNeeded(istr);
			readQtyInHand(istr);
			readPrice(istr);

		}
		else { 
			status.setStatus("Console entry failed!"); 
		}

		return istr;
	}

	void Item::clear()
	{
		status.clear();
	}
	Item::~Item()
	{
		delete[] m_description;
		m_description = nullptr;
	}
	char* Item::getItemDesc() const
	{
		return m_description;
	}
	double Item::getPrice() const
	{
		return m_price;
	}
}