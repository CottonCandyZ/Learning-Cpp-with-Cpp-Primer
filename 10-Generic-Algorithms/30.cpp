//
// Created by CottonCandyZ on 2/22/22.
//

#include <iostream>
#include <vector>


int main() {
    std::istream_iterator<int> iter_in(std::cin), eof;
    std::vector<int> vec;
    std::copy(iter_in, eof, std::back_inserter(vec));
    std::sort(vec.begin(), vec.end());
    std::copy(vec.cbegin(), vec.cend(),
              std::ostream_iterator<int>(std::cout, " "));
    return 0;
}