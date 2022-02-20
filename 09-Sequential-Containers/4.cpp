//
// Created by CottonCandyZ on 2/17/22.
//

#include <iostream>
#include <vector>

using iterator = std::vector<int>::iterator;
using std::vector, std::cout, std::endl;

bool findInRange(iterator begin, const iterator &end, int i) {
    while (begin != end)
        if (*begin++ == i)
            return true;
    return false;
}


int main() {
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8};
    cout << (findInRange(vec.begin(), vec.end(), 3) ? "ture" : "false") << endl;
    cout << (findInRange(vec.begin(), vec.end(), 9) ? "ture" : "false") << endl;
    return 0;
}