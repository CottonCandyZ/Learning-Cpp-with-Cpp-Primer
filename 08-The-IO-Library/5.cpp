//
// Created by CottonCandyZ on 2/16/22.
//

#include <iostream>
#include <vector>
#include <fstream>

using std::ifstream, std::vector, std::string;

void inputFile(const string &file_name, vector<string> &vec) {
    ifstream input(file_name);
    if (input) {
        string buf;
        while (input >> buf) vec.push_back(buf);
    }
}


int main() {
    vector<string> vec;
    inputFile("../08-The-IO-Library/input_2", vec);
    for (auto &s: vec) {
        std::cout << s << std::endl;
    }
    return 0;
}