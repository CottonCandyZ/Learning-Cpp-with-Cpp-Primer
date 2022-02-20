//
// Created by CottonCandyZ on 2/18/22.
//

#include <iostream>
#include <list>
#include <deque>


int main() {
    std::list<int> list_int{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::deque<int> deque_even;
    std::deque<int> deque_odd;
    for (const auto &i: list_int) {
        (i & 0x1 ? deque_odd : deque_even).push_back(i); // 写法有所参考
    }
    for (const auto &i:deque_even) std::cout << i << " ";
    std::cout << std::endl;
    for (const auto &i:deque_odd) std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}