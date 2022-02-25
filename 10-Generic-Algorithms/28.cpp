//
// Created by CottonCandyZ on 2/22/22.
//

#include <iostream>
#include <vector>
#include <list>

void print(const std::list<int> &list) {
    for (const auto &item: list) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> list1, list2, list3;
    auto iter1 = std::inserter(list1, list1.begin());
    auto iter2 = std::back_inserter(list2);
    auto iter3 = std::front_inserter(list3);
    for (const auto &item: vec) {
        *iter1 = item;
        *iter2 = item;
        *iter3 = item;
    }
    /**
     * 估计：
     * list1 : {1, 2, 3, 4, 5, 6, 7, 8, 9}
     * list2 : {1, 2, 3, 4, 5, 6, 7, 8, 9}
     * list3 : {9, 8, 7, 6, 5, 4, 3, 2, 1}
     */
    print(list1);
    print(list2);
    print(list3);


    return 0;
}