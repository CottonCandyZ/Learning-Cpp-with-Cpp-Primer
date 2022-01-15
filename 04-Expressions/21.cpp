#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto &i : vec) {
        i = (i & 0x1) ? i << 1 : i;
    }
    for (auto &i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}