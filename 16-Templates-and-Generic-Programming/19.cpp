//
// Created by CottonCandyZ on 3/17/22.
//

#include <iostream>
#include <vector>

template<typename T>
std::ostream &print(const T &c, std::ostream &os = std::cout) {
    using size_type = typename T::size_type;
    for (size_type i = 0; i != c.size(); ++i) {
        std::cout << c[i] << " ";
    }
    return os;
}

int main() {
    print(std::vector{1,2,3,5}) << std::endl;
    return 0;
}