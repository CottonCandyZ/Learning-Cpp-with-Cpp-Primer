#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto it = nums.begin(); it != nums.end(); it++) {
        *it <<= 1;
    }
    for (auto &i : nums) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}