//
// Created by CottonCandyZ on 2/21/22.
//

#include <iostream>
#include <vector>

using std::string, std::vector;

string make_plural(size_t ctr, const string &word, const string &ending) {
    return (ctr > 1) ? word + ending : word;
}

int main() {
    std::vector<std::string> words;
    std::string buf;

    while (std::cin >> buf) {
        words.push_back(buf);
    }
    int sz = 6;
    auto count = std::count_if(words.begin(), words.end(),
                               [sz](const string &s) { return s.size() <= sz; });
    std::cout << count << " " << make_plural(count, "word", "s")
              << " of length " << sz << " or longer" << std::endl;
    return 0;
}