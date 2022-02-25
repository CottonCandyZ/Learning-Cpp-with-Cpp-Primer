//
// Created by CottonCandyZ on 2/25/22.
//

#include <iostream>
#include <string>
#include <list>

void elimDups(std::list<std::string> &words) {
    words.sort();
    words.unique();
}

int main (){
    std::list<std::string> words;
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