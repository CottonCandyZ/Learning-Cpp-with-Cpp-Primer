//
// Created by CottonCandyZ on 3/2/22.
//

#include <iostream>
#include <string>

int main() {
    size_t size;
    std::cout << "输入字符串的长度：";
    std::cin >> size;
    char *s = new char[size + 1];
    std::cin.ignore(); // 忽略换行符，不然会被 getline 读入
    std::cout << "请输入字符串：";
    // getline 和 get 的区别在于是否读入换行符 https://stackoverflow.com/questions/26873401/difference-between-cin-get-and-cin-getline
    std::cin.getline(s, size + 1); // 超出指定长度，直接截断，get 函数指定的大小包含最后的 \0
    std::cout << s;
    delete [] s;
    return 0;
}