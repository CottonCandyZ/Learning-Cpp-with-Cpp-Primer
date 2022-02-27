//
// Created by CottonCandyZ on 2/28/22.
//

//
// Created by CottonCandyZ on 2/25/22.
//

#include <iostream>
#include <unordered_map>


int main() {
    std::unordered_map<std::string, size_t> word_count;
    std::string word;
    while (std::cin >> word) {
        for (auto& ch : word) ch = tolower(ch);
        word.erase(std::remove_if(word.begin(), word.end(), ispunct),
                   word.end());
        ++word_count[word];
    }
    for (const auto &w:word_count) {

        std::cout<< w.first << " occurs " << w.second
                 << ((w.second > 1) ? " times" : " time") << std::endl;
    }
    return 0;
}