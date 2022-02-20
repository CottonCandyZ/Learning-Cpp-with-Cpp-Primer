//
// Created by CottonCandyZ on 2/18/22.
//

#include <iostream>
#include <vector>


int main() {
    std::vector<int> vec_1{1, 2, 8, 4, 5};
    std::vector<int> vec_2{1, 2, 7, 4, 5};
    std::cout << std::boolalpha << (vec_1 == vec_2) << std::endl;
    return 0;
}