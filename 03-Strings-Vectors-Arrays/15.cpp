#include <iostream>
#include <vector>
#include <string>

using std::string;

int main() {
    std::vector<string> list;
    string input;
    while (std::cin >> input) {
        list.push_back(input);
    }
    for (auto i : list) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}