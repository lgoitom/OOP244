#include "./Phone.h"
#include <iostream>


//cout << prints things out
//cin >> takes things in

using namespace sdds;
using namespace std;

namespace sdds {
	char i;

	void phoneDir(const char* programTitle, const char* fileName) {

		struct Person* person;
		cout << programTitle << " phone directory search\n";
		cout << "-------------------------------------------------------\n";
		cout << "Enter a partial name to search (no spaces) or enter '!' to exit\n> ";
		cin >> i;
		reader(i, programTitle);


	}

	struct Person reader(char input, const char* fileName) {

		struct Person* person = { 0 };

		FILE* fptr;

		int i = 0;

		fptr = fopen("phones.txt", "r");

		//while(fscanf
		//have the first entry for the name as lower case and then use strcmp afterward

		if (fptr != NULL) {

			while (fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n", &person[i].name, &person[i].areaCode, &person[i].prefix, &person[i].number) == 4) {
				i++;
			}
		}
		fclose(fptr);

		return *person;

	}

	void compare(struct Person person[]) {

		//check first char of name and change to lowercase if its uppercase??

		for (int j = 0; j < sizeof(person->name); j++) {
			
			int ascii;

			ascii = (int)person[j].name + 22;

		}



	}

}