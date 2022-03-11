//
// Created by CottonCandyZ on 3/7/22.
//

#ifndef C__PRIMER_HASPTR_5_H
#define C__PRIMER_HASPTR_5_H

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}

    HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }

    HasPtr &operator=(const HasPtr&);

    ~HasPtr();
private:
    std::string *ps;
    int i;
    std::size_t *use;
    void delete_it();
};

inline void HasPtr::delete_it() {
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

HasPtr::~HasPtr() {
    delete_it();
}

HasPtr &HasPtr::operator=(const HasPtr &rhs) {
    ++*rhs.use;
    delete_it();
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

#endif //C__PRIMER_HASPTR_5_H
