#include <iostream>

int main() {
    const int i = 42;
    auto j = i;         // 普通 int 型
    const auto &k = i;  // 底层 const 引用，这里的 const 可有可无，其不会影响值的推断
    auto *p = &i;       // 底层 const 指针
    const auto j2 = i,  // 顶层 const int
        &k2 = i;        // 底层 const 引用
    return 0;
}