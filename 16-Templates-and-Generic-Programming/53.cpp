//
// Created by CottonCandyZ on 3/19/22.
//

#include <iostream>

template<typename T>
std::ostream &print(std::ostream &os, const T &t) {
    return os << t;
}
template<typename T, typename ...Args>
std::ostream &print(std::ostream &os, const T &t, const Args& ... rest) {
    os << t << ", ";
    return print(os, rest...);
}

int main() {
    int i = 0;
    double d = 3.14;
    std::string s = "how now brown cow";
    print(std::cout, i, s, d, 42);
    return 0;
}