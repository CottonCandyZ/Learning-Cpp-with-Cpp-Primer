#include <iostream>
#include <vector>
#include <string>

using std::vector, std::string;

int main() {
    vector<int> v1;
    vector<int> v2(10); // 10 个元素，均为默认值
    vector<int> v3(10, 42); // 10 一个元素
    vector<int> v4{10}; // 一个元素 10
    vector<int> v5{10, 42}; // 10 42 两个元素
    vector<string> v6{10}; // 10 个空的字符串
    vector<string> v7{10, "hi"}; // 10 个 hi
    return 0;
}