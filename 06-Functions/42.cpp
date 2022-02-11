//
// Created by CottonCandyZ on 2/10/22.
//

#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

string make_plural(size_t ctr, const string &word, const string &ending = "s") {
    return (ctr > 1) ? word + ending : word;
}

int main() {
    string str1{"success"}, str2{"failure"};
    cout << make_plural(str1.size(), str1) << endl
         << make_plural(str2.size(), str2) << endl;
    return 0;
}