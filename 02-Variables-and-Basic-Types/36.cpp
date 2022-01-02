#include <iostream>

int main() {
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d; // 改变了 a 的值，d 是 a 的引用
    std::cout << "a: " << a << std::endl
              << "b: " << b << std::endl
              << "c: " << c << std::endl
              << "d: " << d << std::endl;
    return 0;
}