//
// Created by CottonCandyZ on 3/11/22.
//

#ifndef C__PRIMER_DATE_2_H
#define C__PRIMER_DATE_2_H

#include <iostream>

class Date{
    friend std::ostream &operator<<(std::ostream &, const Date &);
    friend std::istream &operator>>(std::istream &, Date &);
public:
    Date() = default;
    Date(unsigned _year, unsigned _month, unsigned _day) : year(_year), month(_month), day(_day) { }
private:
    unsigned year;
    unsigned month;
    unsigned day;
};

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << date.year << "/" << date.month << "/" << date.day;
    return os;
}

std::istream &operator>>(std::istream &is, Date &date) {
    is >> date.year >> date.month >> date.day;
    if (!is) {
        date = Date();
    }
    return is;
}

#endif //C__PRIMER_DATE_2_H
