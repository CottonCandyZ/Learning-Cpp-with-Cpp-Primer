//
// Created by CottonCandyZ on 2/17/22.
//

#include <iostream>
#include <sstream>

using std::istream;

istream &input(istream &is) {
    std::string buffer; // 使用 string 构建一个缓冲
    while (is >> buffer) {
        std::cout << buffer << std::endl;
    }
    is.clear();
    return is;
}

int main() {
    std::istringstream input_str("hello");
    input(input_str);
    return 0;
}