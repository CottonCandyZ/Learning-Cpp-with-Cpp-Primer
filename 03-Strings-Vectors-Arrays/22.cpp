#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> text;
    std::string line;
    while (getline(std::cin, line)) {
        text.push_back(line);
    }

    for (auto it = text.begin(); it != text.end() && !it->empty(); it++) {
        for (auto &c : *it) {
            c = std::toupper(c);
        }
    }

    for (auto &i : text) {
        if (i.empty())
            std::cout << std::endl;
        else
            std::cout << i << std::endl;
    }

    return 0;
}