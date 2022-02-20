//
// Created by CottonCandyZ on 2/20/22.
//

#include <iostream>
#include <string>

using std::string;

string combineName(string name,const string &pre, const string &suf) {
    name.insert(name.begin(), pre.begin(), pre.end());
    name.append(suf);
    return name;
}



int main() {
    std::cout << combineName("CottonCandyZ", "Mr.", ",Jr.") << std::endl;
    return 0;
}