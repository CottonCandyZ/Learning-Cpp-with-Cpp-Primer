//
// Created by CottonCandyZ on 3/13/22.
//

#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums{1, 2, 3, 4, 5};
    int i = 2;
    std::modulus<int> mod;
    auto result = std::all_of(nums.cbegin(), nums.cend(),
                              [&](int n) { return 0 == mod(i, n); });
    std::cout << (result ? "Yes" : "No") << std::endl;
    return 0;
}