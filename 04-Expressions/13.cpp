#include <iostream>

int main() {
    int i;
    double d;
    {
        d = i = 3.5;
        std::cout << "i: " << i << " "
                  << "d: " << d << std::endl;
    }
    {
        i = d = 3.5;
        std::cout << "i: " << i << " "
                  << "d: " << d << std::endl;
    }
    // 3 3
    // 3 3.5
    return 0;
}