#include <iostream>
#include <iterator>
#include <vector>

int main() {
    int int_arr[] = {0, 1, 2, 3, 4, 5};
    std::vector<int> copy(std::begin(int_arr), std::end(int_arr));
    for (auto &i : copy) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}