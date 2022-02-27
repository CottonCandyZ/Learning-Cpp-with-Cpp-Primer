//
// Created by CottonCandyZ on 2/26/22.
//

#include <iostream>
#include <map>


int main() {
    std::map<std::string, size_t> word_count;
    std::string word;
    while (std::cin >> word) {
        for (auto& ch : word) ch = tolower(ch);
        word.erase(std::remove_if(word.begin(), word.end(), ispunct),
                   word.end());
        auto ret = word_count.insert({word, 1});
        if (!ret.second) {
            ++ret.first->second;
        }
    }
    for (const auto &w:word_count) {
        std::cout<< w.first << " occurs " << w.second
                 << ((w.second > 1) ? " times" : " time") << std::endl;
    }
    return 0;
}