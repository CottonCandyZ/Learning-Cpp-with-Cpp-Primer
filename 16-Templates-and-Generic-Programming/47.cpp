//
// Created by CottonCandyZ on 3/18/22.
//

#include <iostream>

void g(int &&i, int &j) {
    std::cout << i << " "
              << std::is_rvalue_reference_v<decltype(i)> << " "
              << j << std::endl;
}

template<typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2) {
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main() {
    int i = 1;
    flip(g, i, 42);
    return 0;
}