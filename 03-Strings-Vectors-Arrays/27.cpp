#include <iostream>

int txt_size() {
    int i = 1;
    return i;
}

int main() {
    unsigned buf_size = 1024;

    // 一 三 确实可以编译通过，github 上的答案称需使用 constexpr
    int ia1[buf_size]; // ok?
    int ia2[4 * 7 - 14]; // ok
    int ia3[txt_size()]; // ok?
    // char st[11] = "fundamental"; // 11 个不够放，要 12 个
    return 0;
}