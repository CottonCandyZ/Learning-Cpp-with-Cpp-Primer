//
// Created by CottonCandyZ on 2/21/22.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::fill_n(vec.begin(), vec.size(), 0);
    for (const auto &item: vec) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}