#include <iostream>
#include <vector>

int main() {
    {  // compare two array
        constexpr int size = 3;
        int array1[3]{1, 2, 3}, array2[3]{1, 2, 3};
        bool isEqual = true;
        for (size_t i = 0; i < size; i++) {
            if (array1[i] != array2[i])
                isEqual = false;
        }
        std::cout << (isEqual ? "相等" : "不等") << std::endl;
    }
    {  // comapre two vector
        std::vector<int> v1{1, 2, 3}, v2{1, 2, 3};
        std::cout << (v1 == v2 ? "相等" : "不等") << std::endl;
    }
    return 0;
}