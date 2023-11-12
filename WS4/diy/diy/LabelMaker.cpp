#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Label.h"
#include "LabelMaker.h"

using namespace std;
namespace sdds{
    LabelMaker::LabelMaker(int noOfLabels){
        m_numOfLabels = noOfLabels;
        m_label = new Label[m_numOfLabels];
    }

    void LabelMaker::readLabels(){
        int i;
        cout << "Enter " << m_numOfLabels << " labels:" << endl;

        for (i = 0; i < m_numOfLabels; i++)
        {
            cout << "Enter label number " << i + 1 << endl << "> ";
            m_label[i].readLabel();
        }
    }

    void LabelMaker::printLabels(){
        int i;
        for (i = 0; i < m_numOfLabels; i++)
        {
            m_label[i].printLabel();
            cout << endl;
        }
    }

    LabelMaker::~LabelMaker(){
        delete[] m_label;
        m_label = nullptr;
    }
}