//
// Created by CottonCandyZ on 2/18/22.
//

#include <list>
#include <vector>
#include <string>
#include <iostream>

int main() {
    std::list<char *> list_char{(char *) "hello", (char *) "world"};
    std::vector<std::string> vec_str;
    vec_str.assign(list_char.begin(), list_char.end());
    for (const auto &i: vec_str) {
        std::cout << i << std::endl;
    }
    return 0;
}