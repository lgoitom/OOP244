#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>

#include "Train.h"

namespace sdds {

	void Train::initialize() {

		trainName = nullptr;
		num = -1;
		departure = -1;
	}

	bool Train::validTime(int value)const {

		if (value >= MIN_TIME && value <= MAX_TIME) {
			int rightDigits = value % 100;

			if (rightDigits <= 59) {
				return true;
			}
		}
		return false;
	}

	bool Train::validNoOfPassengers(int value)const {
		if (value >= 0 && value <= MAX_NO_OF_PASSENGERS) {
			return true;
		}
		return false;
	}



	void Train::set(const char* name) {

		delete[] trainName;
		trainName = nullptr;

		if (name != nullptr && name[0] != '\0') {

			trainName = new char[strlen(name) + 1];

			strcpy(trainName, name);
		}


	}

	void Train::set(int noOfPassengers, int departure) {

		if (!validNoOfPassengers(noOfPassengers) || !validTime(departure)) {
			num = -1;
			this->departure = -1;
		}
		else {
			num = noOfPassengers;
			this->departure = departure;
		}
	}

	void Train::set(const char* name, int noOfPassengers, int departure) {


		set(name);
		set(noOfPassengers, departure);

	}

	void Train::finalize() {
		delete[] trainName;
	}

	bool Train::isInvalid()const {
		return departure == -1 || num == -1 || trainName == nullptr;
	}
	int Train::noOfPassengers() const {
		return num;
	}
	const char* Train::getName() const {
		return trainName;
	}
	int Train::getDepartureTime() const {
		return departure;
	}

	void Train::display() const {

		if (!isInvalid()) {
			std::cout << "NAME OF THE TRAIN:    " << getName() << std::endl;
			std::cout << "NUMBER OF PASSENGERS: " << num << std::endl;
			std::cout << "DEPARTURE TIME:       " << getDepartureTime() << std::endl;
		}
		else {
			std::cout << "Train in an invalid State!" << std::endl;
		}

	}

	bool Train::load(int& boarding) {

		int value;

		std::cout << "Enter number of passengers boarding:\n> ";
		std::cin >> value;

		

			if (value + num < MAX_NO_OF_PASSENGERS) {
				num += value;
				return true;
			}
			else {
				boarding = (value + num) - MAX_NO_OF_PASSENGERS;
				num = MAX_NO_OF_PASSENGERS;
				return false;
			}
	}

	bool Train::load2(const Train& boarding, int& remains) {

		if (this->num + boarding.num < MAX_NO_OF_PASSENGERS) {
			this->num += boarding.num;
			return true;
		}
		else {
			remains = (this->num + boarding.num) - MAX_NO_OF_PASSENGERS;
			this->num = MAX_NO_OF_PASSENGERS;
			return false;

		}
	}

	bool Train::updateDepartureTime() {

		int departuretime = 0;
		std::cout << "Enter new departure time:" << std::endl;
		std::cout << "> ";
		std::cin >> departuretime;

		if (validTime(departuretime)) {
			this->departure = departuretime;
			return true;
		}
		else {
			this->departure = -1;
		}
		return false;
	}

	bool Train::transfer(const Train& from) {

		int remains = 0;

		if (from.isInvalid() || isInvalid()) {
			return false;
		}

		unsigned int length = strlen(trainName) + strlen(", ") + strlen(from.trainName) + 1;

		char* name = new char[length];

		strcpy(name, trainName);
		strcat(name, ", ");
		strcat(name, from.trainName);

		
		if (load2(from, remains)) {
			set(name);
		}
		else {
			std::cout << "Train is full; " << remains << " passengers of " << from.trainName << " could not be boarded!" << std::endl;
			set(name);

		}

		delete[] name;
		return true;
		
	}

}