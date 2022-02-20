//
// Created by CottonCandyZ on 2/17/22.
//

#include <iostream>
#include <vector>

using iterator = std::vector<int>::iterator;
using std::vector, std::cout, std::endl;

iterator findInRange(iterator begin, const iterator &end, int i) {
    while (begin != end)
        if (*begin++ == i)
            return --begin;
    return end;
}


int main() {
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8};
    auto i = findInRange(vec.begin(), vec.end(), 5);
    const iterator &end = vec.end();
    while (i != end) { // 打印出后续的元素
        cout << *i++ << " ";
    }
    cout << endl;
    return 0;
}