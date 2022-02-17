//
// Created by CottonCandyZ on 2/17/22.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int main() {
    std::fstream input("../08-The-IO-Library/input_2");
    std::vector<std::string> vec;
    std::string buf;
    while (std::getline(input, buf)) vec.push_back(buf);
    for (const auto &s:vec) {
        std::istringstream input_str(s);
        std::string word;
        while (input_str >> word) std::cout << word << std::endl;
    }
    return 0;
}