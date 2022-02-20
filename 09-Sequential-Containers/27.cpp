//
// Created by CottonCandyZ on 2/19/22.
//

#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> f_list{1, 2, 3, 4, 5, 6, 7};
    auto prev = f_list.before_begin();
    auto curr = f_list.begin();
    while (curr != f_list.end()) {
        if (*curr % 2) {
            curr = f_list.erase_after(prev);
        } else {
            prev = curr;
            curr++;
        }
    }
    for (const auto &item: f_list) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}