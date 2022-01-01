#include <iostream>

int main() {
    // int null = 0, *p = null; // 不可
    int *p = nullptr;
    // 将指针初始化为空只有 3 中方式，其余两种，推荐使用第一种
    int *p1 = 0;
    int *p2 = NULL;

    // 网上的答案还给了以下两种方法，但编译器均报错
    // cannot initialize a variable of type 'int *' with an lvalue of type 'const int'
    // const int null1 = 0;
    // int* p1 = null1;

    // constexpr int null2 = 0;
    // int* p5 = null2;
    return 0;
}