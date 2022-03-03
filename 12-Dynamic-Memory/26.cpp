//
// Created by CottonCandyZ on 3/3/22.
//

#include <iostream>
#include <memory>

int main() {
    std::allocator<std::string> alloc;
    int n = 3;
    auto const p = alloc.allocate(n);
    std::string s;
    auto q = p;
    while (q != p + n && std::cin >> s) {
        alloc.construct(q++, s); // 在新的版本中已经 removed，改用 allocator_traits

    }
    while (q != p) {
        std::cout << *--q << " ";
        alloc.destroy(q); // 在新的版本中已经 removed
    }
    alloc.deallocate(p, n);
    return 0;
}