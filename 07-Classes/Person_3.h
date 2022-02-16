//
// Created by CottonCandyZ on 2/11/22.
//

#ifndef C__PRIMER_PERSON_3_H
#define C__PRIMER_PERSON_3_H

#include <iostream>
#include <string>

struct Person {
    std::string name;
    std::string address;

    std::string getName() const { return name; }

    std::string getAddress() const { return address; }
};

std::istream &read(std::istream &is, Person &person) {
    is >> person.name >> person.address;
    if (!is) person = Person(); // 可以考虑加上这个，防止错误的输入
    return is;
}

std::ostream &print(std::ostream &os, const Person &person) {
    os << person.getName() << person.getAddress();
    return os;
}

#endif //C__PRIMER_PERSON_3_H
