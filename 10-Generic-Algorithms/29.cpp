//
// Created by CottonCandyZ on 2/22/22.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::istream_iterator, std::string;

int main() {
    std::vector<string> vec;
    std::ifstream in("../10-Generic-Algorithms/29_input");
    if (!in) { // 读取失败
        return -1;
    }
    istream_iterator<string> in_iter(in), eof;
    std::copy(in_iter, eof, std::back_inserter(vec));
    std::copy(vec.cbegin(), vec.cend(),
              std::ostream_iterator<string>(std::cout, " "));
    return 0;
}