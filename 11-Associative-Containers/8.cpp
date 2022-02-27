//
// Created by CottonCandyZ on 2/25/22.
//

#include <iostream>
#include <vector>

using std::string, std::vector, std::cin;

int main() {
    vector<string> words;
    string buf;
    while(cin >> buf) {
        if (std::find(words.begin(), words.end(), buf) != words.end()) {
            std::cout << "has added!" << std::endl;
        } else {
            words.push_back(buf);
        }
    }
    for (const auto &item: words) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}