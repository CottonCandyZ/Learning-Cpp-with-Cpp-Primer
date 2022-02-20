//
// Created by CottonCandyZ on 2/20/22.
//

#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

void findNums(const string &str) {
    string::size_type pos = 0;
    while ((pos = str.find_first_of("0123456789", pos)) != string::npos) {
        cout << "found number at index: " << pos
             << " element is " << str[pos] << endl;
        pos++;
    }
}

void findAlphabet(const string &str) {
    string::size_type pos = 0;
    while ((pos = str.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", pos)) != string::npos) {
        cout << "found alphabet at index: " << pos
             << " element is " << str[pos] << endl;
        pos++;
    }
}

int main() {
    string str{"ab2c3d7R4E6"};
    findNums(str);
    findAlphabet(str);
    return 0;
}