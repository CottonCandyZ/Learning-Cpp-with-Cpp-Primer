//
// Created by CottonCandyZ on 2/19/22.
//

#include <iostream>
#include <forward_list>
#include <string>

using std::forward_list, std::string;

void func(forward_list<string> &f_list_str, const string &s1, const string &s2) {
    auto pre = f_list_str.before_begin();
    auto curr = f_list_str.begin();
    bool inserted = false;
    for (; curr != f_list_str.end(); pre = curr++) {
        if (*curr == s1) {
            curr = f_list_str.insert_after(curr, s2);
            inserted = true;
        }
    }
    if (!inserted) {
        f_list_str.insert_after(pre, s2);
    }

}

int main() {
    forward_list<string> f_list{"Hello", "Hello", "World"};
    func(f_list, "Hello", ", ");
    func(f_list, "pp", "! ");
    for (const auto &s: f_list) {
        std::cout << s;
    }
    std::cout << std::endl;
    return 0;
}