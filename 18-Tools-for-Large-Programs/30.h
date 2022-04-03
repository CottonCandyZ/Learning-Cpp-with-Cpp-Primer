//
// Created by CottonCandyZ on 4/3/22.
//

#ifndef C__PRIMER_30_H
#define C__PRIMER_30_H

class Class {
};

class Base : public Class {
public:
    Base() = default;

    Base(const Base &) = default;

    Base(int);
};

class D1 : virtual public Base {
public:
    D1() = default;

    D1(const D1 &d1) : Base(d1) {}

    D1(int i) : Base(i) {}

};

class D2 : virtual public Base {
public:
    D2() = default;

    D2(const D2 &d2) : Base(d2) {}

    D2(int i) : Base(i) {}
};

class MI : public D1, public D2 {
public:
    MI() = default;

    MI(const MI &mi) : Base(mi), D1(mi), D2(mi) {}

    MI(int i) : Base(i), D1(i), D2(i) {}
};

class Final : public MI, public Class {
    Final() = default;

    Final(const Final &fi) : Base(fi), MI(fi) {}

    Final(int i) : Base(i), Class() {}
};

#endif //C__PRIMER_30_H
