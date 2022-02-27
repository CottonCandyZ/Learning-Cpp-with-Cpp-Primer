//
// Created by CottonCandyZ on 2/27/22.
//

#include <iostream>
#include <map>

using std::multimap, std::string;

int main() {
    multimap<string, string> m_i{{"Stanley B. Lippman", "C++ Primer"},
                                 {"Stanley B. Lippman", "Inside the C++ Object Model"},
                                 {"K&R",                "The C Programming Language"},
                                 {"Hal Abelson",        "Structure and Interpretation of Computer Programs"}};
    string pre;
    for (const auto &item: m_i) {
        if (item.first == pre) {
            std::cout << ", " << item.second;
            continue;
        } else if (!pre.empty()) {
            std::cout << std::endl;
        }
        std::cout << "Author: " << item.first << ", book: " << item.second;
        pre = item.first;
    }
    return 0;
}