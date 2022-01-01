#include <iostream>

int main() {
    // int i, *const cp; // const cp 需要初始化
    // int *p1, *const p2; // const p2 需要初始化
    // const int ic, &r= ic; // ic 需要初始化
    // const int *const p3; // const p3 需要初始化
    const int *p; // 可以
    
    { // a
        int i;
        const int ic = 1; // 初始化
        i = ic; // 可
    }

    { // b
        int *p1;
        int t;
        const int *const p3 = &t;
        // p1 = p3; // p3 包含一个底层 const 而 p1 不包含
        // const int *p1 = p3; // 可
    }

    { // c
        const int ic = 1;
        // int *p1 = &ic; // 不可，将一个 const 赋给一个变量
    }

    { // d
        const int ic = 1;
        const int *const p3 = &ic;
    }

    { // e
        int *p1;
        int *const p2 = p1; //可
    }

    { // f
        int p = 1;
        const int *const p3 = &p;
        const int ic = *p3; // 肯定可以，只是值拷贝
    }

    return 0;

}