//
// Created by CottonCandyZ on 2/21/22.
//

#include <iostream>
#include <vector>
#include <algorithm>

void elimDups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool isShorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}

int main (){
    std::vector<std::string> words;
    std::string buf;
    while (std::cin >> buf) {
        words.push_back(buf);
    }
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), isShorter);
    for (const auto &item: words) {
        std::cout<< item << " ";
    }
    std::cout << std::endl;
    return 0;
}