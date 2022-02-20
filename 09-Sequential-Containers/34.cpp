//
// Created by CottonCandyZ on 2/19/22.
//

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();
    while (iter != vi.end())
        if (*iter % 2)
            iter = vi.insert(iter, *iter); // 不断的回到插入的值
    ++iter; //在 while 外面
    return 0;
}