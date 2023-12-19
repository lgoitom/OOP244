#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include"AidMan.h"
#include<limits>
#include <cstring>
using namespace std;
namespace sdds {

	Menu::Menu(const char* options)
	{
		if (options == nullptr || strlen(options) == 20 ||strlen(options) > 15)
		{
			m_options = nullptr;
		}
		if (options != nullptr)
		{
			if (strlen(options) != 20) {

				delete[] m_options;
				m_options = nullptr;

				m_options = new char[strlen(options) + 1];
				strcpy(m_options, options);
			}
		}
	}

	unsigned int Menu::run() const {
    if (!m_options) {
        cout << "Invalid Menu!\n";
        return 0; 
    }

    const char* prompt = "> ";
    int userInput = 0;
    int maxOptions = 7;
    int selectedOption = 0;

    size_t sequenceNumber = 1;
    size_t index = 0;

    while (index < strlen(m_options)) {
        if (m_options[index] != '\t') {
            cout << sequenceNumber << "- ";
            while (m_options[index] != '\t' && m_options[index] != '\0') {
                cout << m_options[index++];
            }
            cout << endl;
            sequenceNumber++;
        } else {
            index++;
        }
    }

    cout << "---------------------------------\n"
         << "0- Exit\n";

    selectedOption = ut.getint(userInput, maxOptions, prompt);

    return static_cast<unsigned int>(selectedOption);
}


	Menu::~Menu()
	{
		delete[] m_options;
		m_options = nullptr;
	}

}