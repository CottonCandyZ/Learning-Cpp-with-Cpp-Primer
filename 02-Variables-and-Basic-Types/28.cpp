#include<iostream>

int main() {
    // int i, *const cp; // const cp 需要初始化
    // int *p1, *const p2; // const p2 需要初始化
    // const int ic, &r= ic; // ic 需要初始化
    const int *p; // 可以
    return 0;
}