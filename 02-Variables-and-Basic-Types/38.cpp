#include <iostream>

int main() {
    int i = 1;
    const int j = 2;
    
    // 一致
    decltype(i) a = i;
    auto b = i;

    // 不一致
    decltype(j) c = i; // const int
    auto d = j; // int
    return 0;
}