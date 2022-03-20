//
// Created by CottonCandyZ on 3/19/22.
//

#include <iostream>

template<typename T>
std::ostream &print(std::ostream &os, const T &t) {
    return os << t;
}

template<typename T, typename ...Args>
std::ostream &print(std::ostream &os, const T &t, const Args &... rest) {
    os << t << ", ";
    return print(os, rest...);
}

class Foo {

};

int main() {
    Foo f;
    print(std::cout, f);
    return 0;
}