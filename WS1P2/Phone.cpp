#include "./Phone.h"
#include <iostream>


//cout << prints things out
//cin >> takes things in

using namespace sdds;
using namespace std;

namespace sdds {
	char i;

	void phoneDir(const char* programTitle, const char* fileName) {
		cout << programTitle << " phone directory search\n";
		cout << "-------------------------------------------------------\n";
		cout << "Enter a partial name to search (no spaces) or enter '!' to exit\n> ";
		cin >> i;

	}

}