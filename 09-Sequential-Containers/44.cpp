//
// Created by CottonCandyZ on 2/20/22.
//

#include <iostream>
#include <string>

using std::string;

void replace(string &s, const string &oldVal, const string &newVal) {
    for (string::size_type i = 0; i <= s.size() - oldVal.size(); ++i)
        if (s.substr(i, oldVal.size()) == oldVal) {
            s.replace(i, oldVal.size(), newVal);
            i += newVal.size() - 1; // for 会 +1 所以 -1
        }
}

int main() {
    string str{"thothruthothrutho"};
    replace(str, "tho", "though");
    replace(str, "thru", "through");
    std::cout << str << std::endl;
    return 0;
}