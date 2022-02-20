//
// Created by CottonCandyZ on 2/20/22.
//

#include <iostream>

using std::string;

string combineName(string name,const string &pre, const string &suf) {
    name.insert(0, pre);
    name.insert(name.size(), suf);
    return name;
}



int main() {
    std::cout << combineName("CottonCandyZ", "Mr.", ",Jr.") << std::endl;
    return 0;
}