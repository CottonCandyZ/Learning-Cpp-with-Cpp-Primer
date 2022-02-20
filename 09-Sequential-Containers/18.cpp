//
// Created by CottonCandyZ on 2/18/22.
//

#include <iostream>
#include <deque>

using std::cin, std::cout, std::deque, std::string, std::endl;

int main() {
    deque<string> deque_str;
    string buf;
    while(cin >> buf) {
        deque_str.push_back(buf);
    }
    for (const auto &s:deque_str) {
        cout << s << endl;
    }
    return 0;
}