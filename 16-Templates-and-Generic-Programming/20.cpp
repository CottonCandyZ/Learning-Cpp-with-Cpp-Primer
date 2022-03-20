//
// Created by CottonCandyZ on 3/17/22.
//

#include <iostream>
#include <vector>

template<typename T>
std::ostream &print(const T &c, std::ostream &os = std::cout) {
    for (auto begin = c.begin(); begin != c.end(); ++begin) {
        std::cout  << *begin << " ";
    }
    return os;
}

int main() {
    print(std::vector{1,2,3,5}) << std::endl;
    return 0;
}