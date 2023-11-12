#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Label.h"

using namespace std;
namespace sdds{
    Label::Label(){
        strcpy(m_frame, "+-+|+-+|");
        m_label = nullptr;
    }

    Label::Label(const char* frameAvg){
        strcpy(m_frame, frameAvg);
        m_label = nullptr;
    }

    Label::Label(const char* frameAvg, const char* content){
        int length = strlen(content) + 1;
        m_label = new char[length];
        strcpy(m_frame, frameAvg);
        strcpy(m_label, content);
        text(content);
    }


    std::istream& Label::readLabel(){
        char string[71];
        

        if (m_label != nullptr){
            delete[] m_label;
            m_label = nullptr;
        }

        cin.getline(string, 71);

        text(string);


        return cin;
    }

    std::ostream& Label::printLabel()const{
        if (m_label){
            cout << m_frame[0];

            cout.width(strlen(m_label) + 3);

            cout.fill(m_frame[1]);

            cout << m_frame[2] << endl;

            cout << m_frame[7];

            cout.width(strlen(m_label) + 3);

            cout.fill(' ');

            cout << m_frame[3] << endl;

            cout << m_frame[7];

            cout << " " << m_label << " ";

            cout << m_frame[3] << endl;

            cout << m_frame[7];

            cout.width(strlen(m_label) + 3);

            cout.fill(' ');

            cout << m_frame[3] << endl;

            cout << m_frame[6];

            cout.width(strlen(m_label) + 3);

            cout.fill(m_frame[5]);

            cout << m_frame[4];
        }

        return cout;
    }

    Label& Label::text(const char* content){
        
        delete[] m_label;
        m_label = nullptr;
        
        int length = strlen(content) + 1;
        m_label = new char[length];
        strcpy(m_label, content);

        return *this;
    }

    Label::~Label(){
        delete[] m_label;
        m_label = nullptr;
    }
}