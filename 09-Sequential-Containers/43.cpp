//
// Created by CottonCandyZ on 2/20/22.
//

#include <iostream>
#include <string>

using std::string;

void replace(string &s, const string &oldVal, const string &newVal) {
    auto iter = s.begin();
    const auto oldVal_size = oldVal.size();
    if (oldVal_size == 0 || s.size() < oldVal.size()) return;
    while ((iter - s.end()) >= oldVal_size) {
        if (string(iter, iter + oldVal_size) == oldVal) {
            iter = s.erase(iter, iter + oldVal_size);
            iter = s.insert(iter, newVal.begin(), newVal.end());
            iter += newVal.size();
        } else {
            iter++;
        }
    }
}

int main() {
    string str{"thothruthothrutho"};
    replace(str, "tho", "though");
    replace(str, "thru", "through");
    std::cout << str << std::endl;
    return 0;
}