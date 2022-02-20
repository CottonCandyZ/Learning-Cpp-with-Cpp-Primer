//
// Created by CottonCandyZ on 2/18/22.
//

#include <iostream>
//#include <deque> // --
#include <list> // ++

using std::cin, std::cout, std::list, std::string, std::endl; // deque -> list

int main() {
    list<string> list_str; // deque -> list
    string buf;
    while(cin >> buf) {
        list_str.push_back(buf);
    }
    for (const auto &s:list_str) {
        cout << s << endl;
    }
    return 0;
}