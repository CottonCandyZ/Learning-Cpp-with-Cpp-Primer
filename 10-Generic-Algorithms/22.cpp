//
// Created by CottonCandyZ on 2/21/22.
//

#include <iostream>
#include <vector>
#include <functional>

using std::string, std::vector;
using namespace std::placeholders;

string make_plural(size_t ctr, const string &word, const string &ending) {
    return (ctr > 1) ? word + ending : word;
}

bool isLongerThan(const string &s, int sz) {
    return s.size() <= sz;
}

int main() {
    std::vector<std::string> words;
    std::string buf;

    while (std::cin >> buf) {
        words.push_back(buf);
    }
    int sz = 6;
    auto count = std::count_if(words.begin(), words.end(),
                               std::bind(isLongerThan, _1, sz));
    std::cout << count << " " << make_plural(count, "word", "s")
              << " of length " << sz << " or longer" << std::endl;
    return 0;
}