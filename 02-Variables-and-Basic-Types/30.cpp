#include <iostream>

int j = 1;
int main() {
    constexpr int *p = &j;
    const int v2 = 0;  // 顶层 const
    int v1 = v2;       // 没有被限定，只是值拷贝
    int *p1 = &v1, &r1 = v1;
    int i = 0;
    const int *p2 = &v2,  // 底层 const
        *const p3 = &i,   // 顶层 + 底层 const
            &r2 = v2;     // 底层 const
    return 0;
}