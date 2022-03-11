//
// Created by CottonCandyZ on 3/11/22.
//

#ifndef C__PRIMER_FOO_1_H
#define C__PRIMER_FOO_1_H

#include <vector>
#include <iostream>

class Foo {
public:
    Foo sorted() &&;

    Foo sorted() const &;

private:
    std::vector<int> data;
};

Foo Foo::sorted() && {
    std::sort(data.begin(), data.end());
    std::cout << "Foo sorted() &&" << std::endl;
    return *this;
}

Foo Foo::sorted() const & {
    Foo ret(*this);
//    std::sort(ret.data.begin(), ret.data.end());


    std::cout << "Foo sorted() const &" << std::endl;
//    return ret;
//    return ret.sorted();
    return Foo(*this).sorted();
}


#endif //C__PRIMER_FOO_1_H
