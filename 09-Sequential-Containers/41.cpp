//
// Created by CottonCandyZ on 2/20/22.
//

#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<char> vec_c{'a', 'b', 'c', 'd'};
    std::string str(vec_c.begin(), vec_c.end());
    std::cout << str << std::endl;
    return 0;
}