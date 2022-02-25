//
// Created by CottonCandyZ on 2/20/22.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec;
    int buf;
    while (std::cin >> buf) {
        vec.push_back(buf);
    }
    std::cout << std::count(vec.begin(), vec.end(), 5) << std::endl;
    return 0;
}