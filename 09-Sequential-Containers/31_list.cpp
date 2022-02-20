//
// Created by CottonCandyZ on 2/19/22.
//

#include <iostream>
#include <list>

int main() {
    std::list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter =li.begin();
    while (iter != li.end()) {
        if (*iter % 2) {
            iter = li.insert(iter, *iter);
            std::advance(iter, 2);
        } else {
            iter = li.erase(iter);
        }
    }
    for (const auto &i: li) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}