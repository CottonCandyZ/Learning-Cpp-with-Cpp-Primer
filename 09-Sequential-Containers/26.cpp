//
// Created by CottonCandyZ on 2/18/22.
//

#include <iostream>
#include <vector>
#include <list>

using vec_iterator = std::vector<int>::iterator;

int main() {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    std::vector<int> vec(ia, std::end(ia));
    std::list<int> list(vec.begin(), vec.end());

    for (auto it = vec.begin(); it != vec.end();)
        if (*it % 2) it = vec.erase(it); else it++;
    for (auto it = list.begin(); it != list.end();)
        if (!(*it % 2)) it = list.erase(it); else it++;
    for (const auto &item: vec) std::cout << item << " ";
    std::cout << std::endl;
    for (const auto &item: list) std::cout << item << " ";
    std::cout << std::endl;

    return 0;
}