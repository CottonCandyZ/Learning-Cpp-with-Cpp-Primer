//
// Created by CottonCandyZ on 2/20/22.
//

#include <iostream>
#include <string>
#include <vector>

using std::vector, std::string;

int vec_sum_int(const vector<string> &vec_str_int) {
    int sum = 0;
    for (const auto &item: vec_str_int) {
        sum += std::stoi(item);
    }
    return sum;
}

double vec_sum_double(const vector<string> &vec_str_double) {
    double sum = 0;
    for (const auto &item: vec_str_double) {
        sum += std::stod(item);
    }
    return sum;
}

int main() {
    vector<string> vec_str_int{"1", "2", "3", "4", "5", "6"};
    vector<string> vec_str_double{"1.1", "2.2", "3.3", "4.4", "5.5", "6.6"};
    std::cout << vec_sum_int(vec_str_int) << std::endl
              << vec_sum_double(vec_str_double) << std::endl;
    return 0;
}