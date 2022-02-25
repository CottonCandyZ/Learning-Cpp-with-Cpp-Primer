//
// Created by CottonCandyZ on 2/20/22.
//

#include <iostream>
#include <algorithm>
#include <list>

int main() {
    std::list<int> lit;
    int buf;
    while (std::cin >> buf) {
        lit.push_back(buf);
    }
    std::cout << std::count(lit.begin(), lit.end(), 5) << std::endl;
    return 0;
}