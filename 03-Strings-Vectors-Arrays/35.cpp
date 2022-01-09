#include <iostream>

int main() {
    constexpr int size = 10;
    int nums[size];
    int *p = nums;
    for (auto i = p; i != p + size; i++) {
        *i = 0;
    }

    for (auto &i : nums) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}