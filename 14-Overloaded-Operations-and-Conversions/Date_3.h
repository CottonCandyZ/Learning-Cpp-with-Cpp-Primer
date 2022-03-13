//
// Created by CottonCandyZ on 3/11/22.
//

#ifndef C__PRIMER_DATE_3_H
#define C__PRIMER_DATE_3_H

#include <iostream>

class Date{
    friend std::ostream &operator<<(std::ostream &, const Date &);
    friend std::istream &operator>>(std::istream &, Date &);
    friend bool operator==(const Date &, const Date &);
    friend bool operator!=(const Date &, const Date &);
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

bool operator==(const Date &lhs, const Date &rhs){
    return lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day;
}
bool operator!=(const Date &lhs, const Date &rhs){
    return !(lhs == rhs);
}



#endif //C__PRIMER_DATE_3_H
