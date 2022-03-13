//
// Created by CottonCandyZ on 3/13/22.
//

#include <iostream>
#include <vector>

using std::string, std::vector;

class ShorterString {
public:
    bool operator()(const string &s1, const string &s2) const { return s1.size() < s2.size(); }
};

class SizeComp {
public:
    explicit SizeComp(size_t n) : sz(n) {}

    bool operator()(const string &s) const {
        return s.size() >= sz;
    }

private:
    size_t sz;
};

class PrintString {
public:
    explicit PrintString(std::ostream &o = std::cout, char c = ' ') : os(o), sep(c) {}

    void operator()(const string &s) const { os << s << sep; }

private:
    std::ostream &os;
    char sep;
};

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
                     ShorterString());
    auto wc = std::find_if(words.begin(), words.end(),
                           SizeComp(sz));
    auto count = words.end() - wc;
    std::cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << std::endl;
    std::for_each(wc, words.end(),
                  PrintString());
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