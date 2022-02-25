//
// Created by CottonCandyZ on 2/21/22.
//

#include <iostream>
#include <vector>

void elimDups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

int main (){
    std::vector<std::string> words;
    std::string buf;
    while (std::cin >> buf) {
        words.push_back(buf);
    }
    elimDups(words);
    for (const auto &item: words) {
        std::cout<< item << " ";
    }
    std::cout << std::endl;
    return 0;
}