#include <cstddef>
#include <iostream>

int main() {
    constexpr size_t array_size = 10;
    int ia[array_size];
    for (size_t ix = 0; ix <= array_size; ix++) { // 越界了，显然不能等于 10，数组可访问范围是 0..9
        ia[ix] = ix;
    }

    return 0;
}