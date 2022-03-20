//
// Created by CottonCandyZ on 3/16/22.
//

#include <iostream>
#include <vector>
#include <list>

template<typename T, typename U>
T Find(T begin, T end, const U &value) {
    for (; begin != end; ++begin) {
        if (*begin == value) {
            return begin;
        }
    }
    return end;
}


int main() {
    std::vector<int> v_i{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<std::string> list_s{"h", "e", "l", "l", "o"};
    if (Find(v_i.begin(), v_i.end(), 1) != v_i.end()) std::cout << "已找到" << std::endl;
    else std::cout << "未找到" << std::endl;
    if (Find(list_s.begin(), list_s.end(), "o") != list_s.end()) std::cout << "已找到" << std::endl;
    else std::cout << "未找到" << std::endl;
    return 0;
}