//
// Created by CottonCandyZ on 2/15/22.
//

#ifndef C__PRIMER_43_H
#define C__PRIMER_43_H

class NoDefault {
public:
    NoDefault(const int i) {}
};

class C {
public:
    C() : c_member(0) {}
private:
    NoDefault c_member;
};


#endif //C__PRIMER_43_H
