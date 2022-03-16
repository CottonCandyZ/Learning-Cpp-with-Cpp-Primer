//
// Created by CottonCandyZ on 3/15/22.
//

#include <iostream>

class Base {
public:
    virtual int fcn() {
        std::cout << "Base::fcn()" << std::endl;
        return 0;
    };
};

class D1 : public Base {
public:
    int fcn() override {
        std::cout << "D1::fcn()" << std::endl;
        return 0;
    };

    virtual void f2() {
        std::cout << "D1::f2()" << std::endl;
    };
};

class D2 : public D1 {
public:
    int fcn(int);
    int fcn() override {
        std::cout << "D2::fcn()" << std::endl;
        return 0;
    }
    void f2() override {
        std::cout << "D2::f2()" << std::endl;
    }
};

int main() {
    Base bobj; D1 d1obj; D2 d2obj;

    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;

    bp1->fcn();
    bp2->fcn();
    bp3->fcn();

    D1 *d1p = &d1obj; D2 *d2p = &d2obj;
//    bp2->f2();
    d1p->f2();
    d2p->f2();

    return 0;
}