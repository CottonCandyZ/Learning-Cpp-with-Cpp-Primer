//
// Created by CottonCandyZ on 2/22/22.
//

#include <iostream>
#include <vector>
#include <list>

int main() {
    std::vector<int> vec{1,1,1,1,2,3,4,4,4,5,6,6,7,1,2,3,4,5};
    std::list<int> unique_list;
    std::unique_copy(vec.begin(), vec.end(), std::back_inserter(unique_list));
    for (const auto &item: unique_list) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}