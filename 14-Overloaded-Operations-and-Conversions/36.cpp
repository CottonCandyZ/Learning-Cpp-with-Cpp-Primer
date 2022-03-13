//
// Created by CottonCandyZ on 3/12/22.
//

#include "InputString_1.h"
#include <vector>

int main() {
    InputString is;
    std::string temp;
    std::vector<std::string> v;
    while (!(temp = is()).empty()) {
        v.push_back(temp);
    }
    std::for_each(v.begin(), v.end(),
                  [](const std::string &s) { std::cout << s << std::endl; });
    return 0;
}