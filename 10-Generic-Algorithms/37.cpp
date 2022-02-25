//
// Created by CottonCandyZ on 2/24/22.
//

#include <iostream>
#include <list>
#include <vector>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> lst(vec.crbegin() + (vec.size() - 7), vec.crend() - 2); // 也可使用 reverse_copy
    for (const auto &item:lst) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}