//
// Created by CottonCandyZ on 2/23/22.
//

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto i = vec.cend(); i != vec.begin();) {
        std::cout << *--i << " ";
    }
    std::cout << std::endl;

    return 0;
}