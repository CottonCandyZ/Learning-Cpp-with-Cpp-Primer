//
// Created by CottonCandyZ on 2/21/22.
//

#include <iostream>
#include <vector>

using std::string, std::vector;

void elimDups(vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

string make_plural(size_t ctr, const string &word, const string &ending) {
    return (ctr > 1) ? word + ending : word;
}


void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);

    std::stable_sort(words.begin(), words.end(),
                     [](const string &s1, const string &s2) { return s1.size() < s2.size(); });
    auto wc = std::find_if(words.begin(), words.end(),
                           [sz](const string &s) { return s.size() >= sz; });
    auto count = words.end() - wc;
    std::cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << std::endl;
    std::for_each(wc, words.end(),
                  [](const string &s) { std::cout << s << " "; });
}

int main() {
    std::vector<std::string> words;
    std::string buf;
    while (std::cin >> buf) {
        words.push_back(buf);
    }
    biggies(words, 5);
    return 0;
}