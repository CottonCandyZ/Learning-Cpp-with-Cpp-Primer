#include <iostream>

int main() {
    int i = 0, &r = i;
    auto a = r;
    a = 42; // ok，正常推断 a 就是 int 而已

    const int ci = i, &cr = ci;
    auto b = ci;
    b = 42; // ok，不会推断顶层 const

    auto c = cr;
    c = 42; // ok，这个和上一个一样的

    auto d = &i;
    // d = 42; // 不可直接更改指针的值

    auto e = &ci;
    // e = 42; // 同样不可以更改指针的值，这里同样保留了底层 const，不可以通过 e 修改 ci 的值

    auto &g = ci;
    // g = 42; // g 是 ci 的引用，是一个常量引用（常量的引用），auto 自动加上顶层 const，因此不可修改 g 的值

    return 0;
}