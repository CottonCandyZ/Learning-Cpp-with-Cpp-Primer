#include <iostream>
#include <vector>

int main() {
    std::vector<int> list;
    int input;
    while (std::cin >> input) {
        list.push_back(input);
    }
    for (auto i : list) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}