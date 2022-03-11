//
// Created by CottonCandyZ on 3/5/22.
//

#ifndef C__PRIMER_HASPTR_4_H
#define C__PRIMER_HASPTR_4_H

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) :
            ps(new std::string(s)), i(0) {}

    HasPtr(const HasPtr &orig) :
            ps(new std::string(*orig.ps)),
            i(orig.i) {}

    HasPtr &operator=(const HasPtr &rhs) {
        std::string *temp = new std::string(*rhs.ps);
        delete ps;
        ps = temp;
        i = rhs.i;
        return *this;
    }

    ~HasPtr() {
        delete ps;
    }

private:
    std::string *ps;
    int i;
};


#endif //C__PRIMER_HASPTR_4_H
