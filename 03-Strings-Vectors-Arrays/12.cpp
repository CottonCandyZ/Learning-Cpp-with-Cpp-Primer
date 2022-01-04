#include <iostream>
#include <vector>
#include <string>

using std::vector, std::string;

int main() {
    vector<vector<int>> ivec; // 可
    // vector<string> svec = ivec; // 不可，类型不匹配
    vector<string> svec(10, "null"); // 可

    return 0;
}