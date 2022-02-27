//
// Created by CottonCandyZ on 2/26/22.
//

#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> m{{"hello", 1}};
    std::map<std::string, int>::key_type get = "hello"; // std::string
    std::map<std::string, int>::mapped_type value = m[get]; // int
    return 0;
}