//
// Created by CottonCandyZ on 2/20/22.
//

#include <iostream>
#include <string>

using std::string;

bool meetRequiredWord(const string &str) {
    if (str.find_first_of("bdfhkltgjpqy") == string::npos)
        return true;
    return false;
}

int main() {
    string buf, selected;
    while (std::cin >> buf) {
        if (buf.size() > selected.size() && meetRequiredWord(buf)) {
            selected = buf;
        }
    }
    std::cout << selected << std::endl;
    return 0;
}