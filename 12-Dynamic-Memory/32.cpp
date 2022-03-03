//
// Created by CottonCandyZ on 3/4/22.
//

#include <iostream>
#include "QueryResult_3.h"

void runQueries(std::ifstream &infile) {
    TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main() {
    std::ifstream file("../12-Dynamic-Memory/28_input");
    runQueries(file);
    return 0;
}