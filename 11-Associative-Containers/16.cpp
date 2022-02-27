//
// Created by CottonCandyZ on 2/26/22.
//


#include <iostream>
#include <map>

int main() {
    std::map<int, int> m_ii{{1, 2}};
    auto iter = m_ii.begin();
    iter->second = 3;
    for (const auto &item:m_ii) {
        std::cout << item.first << " " << item.second << std::endl;
    }
    return 0;
}