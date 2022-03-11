//
// Created by CottonCandyZ on 3/8/22.
//

#include "HasPtr_7.h"
#include <vector>

int main() {
    // 全逆序
    std::vector<HasPtr> v1{HasPtr("h4"), HasPtr("h3"), HasPtr("h2"), HasPtr("h1")};
    // 顺序
    std::vector<HasPtr> v2{HasPtr("h1"), HasPtr("h2"), HasPtr("h3"), HasPtr("h4")};
    std::sort(v1.begin(), v1.end());
    std::cout << "------------------------------------------------------" << std::endl;
    std::sort(v2.begin(), v2.end());
    return 0;
}