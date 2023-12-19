#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include"Menu.h"
#include "Date.h"
#include"iProduct.h"
#include<fstream>
namespace sdds {
	const int sdds_max_num_items = 100;
	class AidMan {
		char* fileName;
		Menu mainMenu;
		Date m_date;
		iProduct* Product[sdds_max_num_items];
		int noOfRecs{};

		unsigned int menu() const;
	public:
		AidMan(const char* file = nullptr);
		AidMan(const AidMan& other) = delete;
		AidMan& operator=(const AidMan& other) = delete;
		~AidMan();


		void run();
		void save();
		bool load(const char* filename);
		int list(const char* sub_desc = nullptr) const;

		operator bool()const;
		void deallocate();
	};

}
#endif // !AIDMAN_H
