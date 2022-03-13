//
// Created by CottonCandyZ on 3/13/22.
//

#include <iostream>
#include <map>
#include <string>

int add(int i, int j) { return i + j; }

struct divide {
    int operator()(int denominator, int divisor) {
        return denominator / divisor;
    }
};


int main() {
    auto mod = [](int i, int j) { return i % j; };
    std::map<std::string, std::function<int(int, int)>> binops = {
            {"+", add},
            {"-", std::minus<int>()},
            {"/", divide()},
            {"*", [](int i, int j) { return i * j; }},
            {"%", mod}
    };
    std::string sign;
    int n1, n2;
    std::cin >> n1 >> sign >> n2;
    std::cout << binops[sign](n1, n2) << std::endl;
    return 0;
}