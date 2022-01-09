#include <iostream>
#include <vector>

int main() {
    std::vector<int> int_vec{1, 2, 3, 4, 5, 6};
    int int_arr[int_vec.size()]; // 这里使用一个编译器插件，支持动态数组
    for (size_t i = 0; i < int_vec.size(); i++) {
        int_arr[i] = int_vec[i];
    }
    for (auto &i : int_arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}