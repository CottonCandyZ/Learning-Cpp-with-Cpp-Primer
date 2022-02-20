//
// Created by CottonCandyZ on 2/18/22.
//

#include <iostream>
#include <list>
#include <vector>

void print(const std::vector<double> &vec) {
    for (const auto &i: vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::list<int> list_a{1, 2, 3, 4, 5};
    std::vector<double> vec_int{1, 2, 3, 4};
    std::vector<double> vec_double_a(list_a.begin(), list_a.end());
    std::vector<double> vec_double_b(vec_int.begin(), vec_int.end());
    print(vec_double_a);
    print(vec_double_b);
    return 0;
}