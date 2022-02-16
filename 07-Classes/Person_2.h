//
// Created by CottonCandyZ on 2/11/22.
//

#ifndef C__PRIMER_PERSON_2_H
#define C__PRIMER_PERSON_2_H

#include <string>

struct Person {
    std::string name;
    std::string address;

    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
};


#endif //C__PRIMER_PERSON_2_H
