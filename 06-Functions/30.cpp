//
// Created by CottonCandyZ on 2/9/22.
//

#include <string>
bool  str_subrange(const std::string &str1, const std::string &str2) {
    if (str1.size() == str2.size())
        return str1 == str2;
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
    for (decltype(size) i = 0; i < size; ++i) {
        if (str1[i] != str2[i])
//            return; // 这会直接编译不通过 FAILED
            return 1;
    }
    return 2; // 不写会给个 WARNING
}



int main() {

    return 0;
}