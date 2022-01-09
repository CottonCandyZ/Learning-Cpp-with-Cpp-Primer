#include <iostream>
#include <vector>

int main() {
    int nums[10];
    for (size_t i = 0; i < 10; i++) {
        nums[i] = i;
    }
    int copy[10];
    for (size_t i = 0; i < 10; i++) {
        copy[i] = nums[i];
    }

    std::vector<int> v_nums(10);
    int temp = 0;
    for (auto &i : v_nums) {
        i = nums[temp++];
    }
    for (auto &i : v_nums) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
