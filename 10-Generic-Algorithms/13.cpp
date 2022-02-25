//
// Created by CottonCandyZ on 2/21/22.
//

#include <iostream>
#include <vector>

bool isLongerThanFive(const std::string &s) {
    return s.length() >= 5;
}

int main() {
    std::vector<std::string> words;
    std::string buf;
    while (std::cin >> buf) {
        words.push_back(buf);
    }
    auto end_of_words = std::partition(
            words.begin(),
            words.end(),
            isLongerThanFive);
    for (auto p = words.cbegin(); p != end_of_words; p++) {
        std::cout << *p << " ";
    }
    std::cout << std::endl;
    return 0;
}