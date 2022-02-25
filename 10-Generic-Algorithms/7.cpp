//
// Created by CottonCandyZ on 2/21/22.
//

#include <iostream>
#include <vector>
#include <list>


int main() {
    {
        std::vector<int> vec;
        std::list<int> lst;
        int i;
        while (std::cin >> i) {
            lst.push_back(i);
        } // 或者使用 resize 将 vector 调整至 lst 的大小
        std::copy(lst.cbegin(), lst.cend(), std::back_inserter(vec)); // 改为使用 back_inserter，因其没有初始化
        for (const auto &item: vec) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> vec;
        vec.reserve(10); // 分配空间没用，得占位，这一行可以选择去掉或改为 resize(10)
        std::fill_n(std::back_inserter(vec), 10, 0); // 或使用 back_inserter
    }
    return 0;
}