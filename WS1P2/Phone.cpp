#include "./Phone.h"
#include "./cStrTools.h"

using namespace sdds;
using namespace std;

namespace sdds {

	int readFile(const char* fileName, Person* p, char ch[][100]) {

		int i = 0;
		FILE* fptr = fopen(fileName, "r");


		while (fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n", p[i].name, p[i].areaCode, p[i].prefix, p[i].number) == 4) {

			toLowerCaseAndCopy(ch[i], p[i].name);
			i++;
		}
		fclose(fptr);

		return i;
	}

	int caseCheck(const char* list, const char* input) {
		int listTemp = strLen(list);
		int inputTemp = strLen(input);
		int i;
		int j;

		for (i = 0; i <= listTemp - inputTemp; i++) {

			int match = 1;

			do {

				for (j = 0; j < inputTemp; j++) {
					if (toLower(list[i + j]) != toLower(input[j])) {
						match = 0;
					}
				}

				if (match) {
					return 1;
				}

			} while (match);
		}
		return 0;
	}

	void search(const char* input, Person* p, char ch[][100], int j) {
		int found = 0;

		for (int k = 0; k < j; k++) {
			if (caseCheck(ch[k], input) || caseCheck(p[k].name, input)) {
				cout << p[k].name << ": (" << p[k].areaCode << ") " << p[k].prefix << "-" << p[k].number << endl;
				found = 1;
			}
		}

		if (!found) {
			return;
		}
	}

	void phoneDir(const char* programTitle, const char* fileName) {
		const int i = 100;
		Person p[i];
		char ch[i][100] = { 0 };
		char input[100];
		int results = 0;


		cout << programTitle << " phone directory search" << endl;
		cout << "-------------------------------------------------------" << endl;

		results = readFile(fileName, p, ch);
		if (results == 0) {
			return;
		}

		while (results) {
			cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
			cout << "> ";
			cin.getline(input, 100);

			if (input[0] == '!') {
				cout << "Thank you for using " << programTitle << " directory." << endl;
				cout << "\n-------------------------------------------------------" << endl;
				cout << "Broken Phone Book phone direcotry search" << endl;
				cout << "-------------------------------------------------------" << endl;
				cout << "badDataFile.txt file not found!\nThank you for using Broken Phone Book directory." << endl;
				break;
			}
			else {


			search(input, p, ch, results);
			
			}
		}
	}
}
