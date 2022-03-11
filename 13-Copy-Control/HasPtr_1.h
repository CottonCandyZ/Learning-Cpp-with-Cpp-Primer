//
// Created by CottonCandyZ on 3/5/22.
//

#ifndef C__PRIMER_HASPTR_1_H
#define C__PRIMER_HASPTR_1_H

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) :
            ps(new std::string(s)), i(0) { }

    HasPtr(const HasPtr &orig) :
            ps(new std::string(*orig.ps)),
            i(orig.i) {}
private:
    std::string *ps;
    int i;
};


#endif //C__PRIMER_HASPTR_1_H
