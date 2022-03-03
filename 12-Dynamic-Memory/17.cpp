//
// Created by CottonCandyZ on 3/1/22.
//


#include <iostream>

int main() {
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    using IntP = std::unique_ptr<int>;
//    IntP p0(ix); // 不可以，显然不支持直接用 int 初始化
//    IntP p1(pi); // 不可以，由于 ix 不是动态内存分配出来的，所以会被自动回收，而 unique_ptr 的析构函数会再次回收，会导致 pointer being freed was not allocated 错误

    IntP p2(pi2); // 可 但是会导致 pi2 指向未知区域
//    IntP p3(&ix); // 不可 等价于 p1
    IntP p4(new int(2048)); // 可
    IntP p5(p2.get()); // 不可，会导致回收两次，导致一个错误：pointer being freed was not allocated
    return 0;
}