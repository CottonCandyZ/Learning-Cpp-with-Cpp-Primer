#include <iostream>

int main() {
    const int v2 = 0;  // 顶层 const
    int v1 = v2;       // 没有被限定，只是值拷贝
    int *p1 = &v1, &r1 = v1;
    int i = 0;
    const int *p2 = &v2,  // 底层 const
        *const p3 = &i,   // 顶层 + 底层 const
            &r2 = v2;     // 底层 const

    r1 = v2; // 可以，r1 是对 v1 的引用
    // p1 = p2; // 底层 const 必须赋给 底层 const，显然 p1 不是
    p2 = p1; // 完全可以，底层 const 不可以改所指向的值，但是可以改自身的值
    // p1 = p3; // 不可，同「底层 const 必须赋给 底层 const，显然 p1 不是」
    p2 = p3; // 底层 const 可以赋给 底层 const。 但是，若 p3 = p2，则将报错，因为 p3 是一个 const 指针，不可以修改
    
    return 0;
}