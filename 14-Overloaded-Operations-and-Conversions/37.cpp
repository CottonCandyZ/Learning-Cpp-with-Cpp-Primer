//
// Created by CottonCandyZ on 3/12/22.
//

#include <vector>
#include <iostream>

class CheckEqual {
    int value;

public:
    explicit CheckEqual(int v) : value(v) {}

    bool operator()(int elem) const { return elem == value; }
};

int main() {
    std::vector<int> vec = {3, 2, 1, 4, 3, 7, 8, 6};
    std::replace_if(vec.begin(), vec.end(), CheckEqual(3), 5);
    std::for_each(vec.begin(), vec.end(), [](const int i) { std::cout << i << " "; });
}