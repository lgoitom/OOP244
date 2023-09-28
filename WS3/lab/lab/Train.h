#ifndef SDDS_TRAIN_H_
#define SDDS_TRAIN_H_

#include <iostream>
#include <cstring>
#include <iomanip>

 
namespace sdds {
	const int MIN_TIME = 700;
	const int MAX_TIME = 2300;
	const int MAX_NO_OF_PASSENGERS = 1000;
	class Train {
	private:
		char* trainName;
		int num;
		int departure;

	public:
		
		void initialize();
		bool validTime(int value)const;
		bool validNoOfPassengers(int value)const;
		void set(const char* name);
		void set(int noOfPassengers, int departure);
		void set(const char* name, int noOfPassengers, int departure);
		void finalize();
		bool isInvalid()const;
		int noOfPassengers() const;
		const char* getName() const;
		int getDepartureTime() const;
		void display() const;

	};
}
#endif
