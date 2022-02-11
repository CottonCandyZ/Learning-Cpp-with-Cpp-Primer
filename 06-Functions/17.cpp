//
// Created by CottonCandyZ on 1/28/22.
//

#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

bool is_contain_uppercase(const string &s) {
    for (auto &c: s) { // 这里可以用 std::all_of()
        if (std::isupper(c)) return true;
    }
    return false;
}

void convert_to_lowercase(string &s) {
    for (auto &c: s) {
        c = std::tolower(c, std::locale());
    }
}

int main() {
    string s{"Hello"};
    cout << s << (is_contain_uppercase(s) ? " 包含大写字母" : " 不包含大写字母") << endl;
    convert_to_lowercase(s);
    cout << "修正后：" << s << endl;

    return 0;
}