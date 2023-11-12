#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef NAMESPACE_LABEL_H
#define NAMESPACE_LABEL_H

namespace sdds
{
    class Label{
    private:
        char* m_label;
        char m_frame[9];

    public:
        Label();
        Label(const char* frameAvg);
        Label(const char* frameAvg, const char* content);
        ~Label();
        std::istream& readLabel();
        std::ostream& printLabel()const;
        Label& text(const char* content);
    };
}

#endif