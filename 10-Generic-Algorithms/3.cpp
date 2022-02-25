//
// Created by CottonCandyZ on 2/20/22.
//

#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << std::accumulate(vec.begin(), vec.end(), 0) << std::endl;
    return 0;
}