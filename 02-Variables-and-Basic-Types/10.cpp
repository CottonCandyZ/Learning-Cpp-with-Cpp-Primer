#include <iostream>
std::string global_str; // 空
int global_int; // zero
int main() {
    int local_int; // 一个随机值，内置类型，函数内自动初始化结果是未知的
    std::string local_str; // 空，这个应该是提供了默认构造函数，所以值不是随机的
    std::cout << global_int << std::endl
              << global_str << std::endl
              << local_int << std::endl
              << local_str << std::endl;
    return 0;
}