//
// Created by CottonCandyZ on 3/19/22.
//

#include <iostream>
#include "debug_rep_1.h"


template<typename T>
std::ostream &print(std::ostream &os, const T &t) {
    return os << t;
}
template<typename T, typename ...Args>
std::ostream &print(std::ostream &os, const T &t, const Args& ... rest) {
    os << t << ", ";
    return print(os, rest...);
}

template <typename ... Args>
std::ostream &errorMsg(std::ostream &os, const Args&... rest) {
    return print(os, debug_rep(rest)...);
}

int main() {
    int i = 0;
    double d = 3.14;
    std::string s = "how now brown cow";
    errorMsg(std::cerr, i, d, s, 42);
    return 0;
}