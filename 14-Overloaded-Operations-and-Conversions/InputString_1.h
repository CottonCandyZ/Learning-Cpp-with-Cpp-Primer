//
// Created by CottonCandyZ on 3/12/22.
//

#ifndef C__PRIMER_INPUTSTRING_1_H
#define C__PRIMER_INPUTSTRING_1_H

#include <iostream>

class InputString {
public:
    InputString(std::istream &i = std::cin) : is(i) {}

    std::string operator()() {
        std::string temp;
        std::getline(is, temp);
        return is ? temp : std::string();
    }

private:
    std::istream &is;
};

#endif //C__PRIMER_INPUTSTRING_1_H
