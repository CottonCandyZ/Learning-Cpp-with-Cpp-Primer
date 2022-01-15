#include <iostream>

int main() {
    int x[10];
    int *p = x;
    std::cout << sizeof(x) / sizeof(*x) << std::endl // 数组大小除以单个元素的大小
              << sizeof(p) / sizeof(*p) << std::endl; // 指针大小除以 int 大小
    return 0;
}