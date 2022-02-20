//
// Created by CottonCandyZ on 2/19/22.
//

#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> fi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto pre = fi.before_begin();
    auto curr = fi.begin();
    while (curr != fi.end()) {
        if (*curr % 2) {
             fi.insert_after(pre, *curr);
             pre = curr;
             curr++;
        } else {
            curr = fi.erase_after(pre);
        }
    }
    for (const auto &i: fi) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}