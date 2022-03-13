//
// Created by CottonCandyZ on 3/11/22.
//

#ifndef C__PRIMER_DATE_1_H
#define C__PRIMER_DATE_1_H

#include <iostream>

class Date{
    friend std::ostream &operator<<(std::ostream &, const Date &);
public:
    Date() = default;
    Date(unsigned _year, unsigned _month, unsigned _day) : year(_year), month(_month), day(_day) { }
    Date(std::istream &in) { in >> year >> month >> day; }
private:
    unsigned year;
    unsigned month;
    unsigned day;
};

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << date.year << "/" << date.month << "/" << date.day;
    return os;
}

#endif //C__PRIMER_DATE_1_H
