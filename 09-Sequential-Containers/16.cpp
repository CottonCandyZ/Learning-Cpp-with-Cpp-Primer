//
// Created by CottonCandyZ on 2/18/22.
//

#include <iostream>
#include <vector>
#include <list>

int main() {
    std::vector<int> vec_1{1, 2, 8, 4, 5};
    std::list<int> list{1, 2, 7, 4, 5};
    std::cout  << std::boolalpha << (vec_1 == std::vector<int>(list.begin(), list.end())) << std::endl;
    return 0;
}