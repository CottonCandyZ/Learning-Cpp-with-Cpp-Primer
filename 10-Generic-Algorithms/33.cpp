//
// Created by CottonCandyZ on 2/23/22.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::string, std::ostream_iterator, std::ofstream;

void outPutOddAndEven(const string &input_file_name, const string &odd_output_file_name,
                      const string &even_output_file_name) {
    std::ifstream in(input_file_name);
    std::vector<int> vec;
    std::istream_iterator<int> iter_in(in), eof;
    std::copy(iter_in, eof, std::back_inserter(vec)); // 输入

    ofstream odd_out(odd_output_file_name);
    ofstream even_out(even_output_file_name);
    ostream_iterator<int> iter_even_out(even_out, "\n");
    std::copy_if(vec.cbegin(), vec.cend(), ostream_iterator<int>(odd_out, " "),
                 [](const int &i) { return i % 2; });
    std::copy_if(vec.cbegin(), vec.cend(), ostream_iterator<int>(even_out, " "),
                 [](const int &i) { return !(i % 2); });
}

int main() {
    outPutOddAndEven("../10-Generic-Algorithms/33_input",
                     "../odd_output", "../even_output");
    return 0;
}