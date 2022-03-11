//
// Created by CottonCandyZ on 3/11/22.
//

#ifndef C__PRIMER_HASPTR_9_H
#define C__PRIMER_HASPTR_9_H

#include <string>
#include <iostream>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) :
            ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &orig) :
            ps(new std::string(*orig.ps)),
            i(orig.i) {}
    HasPtr &operator=(const HasPtr& rhs) {
        std::string *temp = new std::string(*rhs.ps);
        delete ps;
        ps = temp;
        i = rhs.i;
        return *this;
    }
    friend bool operator<(const HasPtr &, const HasPtr &);
    friend void swap(HasPtr &, HasPtr&);
    ~HasPtr() {
        delete ps;
    }
    HasPtr(HasPtr &&);
    HasPtr &operator=(HasPtr &&);
    HasPtr &operator=(HasPtr rhs);
private:
    std::string *ps;
    int i;
};


void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "执行：swap(HasPtr &, HasPtr &)" << std::endl;
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs) {
    return *lhs.ps < *rhs.ps;
}

HasPtr::HasPtr(HasPtr &&h) :ps(h.ps), i(h.i) {
    h.ps = nullptr;
}

HasPtr &HasPtr::operator=(HasPtr &&rhs) {
    if (&rhs != this) {
        delete ps;
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
    }
    return *this;
}

HasPtr &HasPtr::operator=(HasPtr rhs) {
    swap(*this, rhs);
    return *this;
}

#endif //C__PRIMER_HASPTR_9_H
