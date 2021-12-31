#include <iostream>

int main() {
    int *p = nullptr, i = 1, j = 2;
    p = &i;
    *p = 3;
    std::cout << "change by pointer i: " << i << std::endl;
    p = &j;
    std::cout << "pointer changed *p: " << *p << std::endl;
    return 0;
}