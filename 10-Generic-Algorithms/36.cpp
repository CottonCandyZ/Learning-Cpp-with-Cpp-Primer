//
// Created by CottonCandyZ on 2/24/22.
//

#include <iostream>
#include <list>

int main() {
    std::list<int> lst{1, 2, 3, 4, 5, 6, 7, 8, 0, 9};
    auto found = std::find(lst.crbegin(), lst.crend(), 0);
    std::cout << *found << " 在 " << *found.base() << " 之前" <<std::endl;
    return 0;
}