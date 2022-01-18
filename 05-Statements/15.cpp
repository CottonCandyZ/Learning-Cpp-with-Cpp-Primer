#include <iostream>

int main() {
    {
        int input;
        while (std::cin >> input) {
            /* ... */
        }

        int nums[10] = {0};

        for (size_t i = 0; i != 10; ++i) {
            nums[i] = 1;
        }
    }

    {   // 相互替代                                      
        for (int input; std::cin >> input;) { /* */
        }
        
        int nums[10] = {0};
        int i = 0;
        while (i != 10) {
            nums[i++] = 1;
        }
    }

    return 0;
}