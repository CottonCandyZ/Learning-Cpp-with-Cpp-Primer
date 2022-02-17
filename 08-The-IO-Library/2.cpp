//
// Created by CottonCandyZ on 2/16/22.
//

#include <iostream>

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
    input(std::cin);
    return 0;
}