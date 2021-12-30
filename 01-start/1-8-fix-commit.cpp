#include <iostream>
int main() {
    std::cout << "/*";
    std::cout << "*/";
    // std::cout << /* "*/" */; // 这个显然是错的
    std::cout << /* "*/" /* "/*" */; // 这个有点乱，但做个匹配就行
    return 0;
}