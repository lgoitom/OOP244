#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef NAMESPACE_LABELMAKER_H
#define NAMESPACE_LABELMAKER_H

#include <iostream>
#include <cstring>

namespace sdds{
    class LabelMaker{
    private:
        int m_numOfLabels;
        Label* m_label;

    public:
        LabelMaker(int noOfLabels);
        void readLabels();
        void printLabels();
        ~LabelMaker();
    };
}

#endif
