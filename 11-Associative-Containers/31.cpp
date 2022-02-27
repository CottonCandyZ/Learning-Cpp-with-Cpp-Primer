//
// Created by CottonCandyZ on 2/27/22.
//

#include <iostream>
#include <map>

using std::multimap, std::string;

bool removeByKey(multimap<string, string> &m, const string &key) {
    auto iter = m.find(key);
    if (iter == m.end()) {
        return false;
    }
    for (; iter != m.end() && iter->first == key;) {
        iter = m.erase(iter);
    }
    return true;
}

int main() {
    multimap<string, string> m_i{{"Stanley B. Lippman", "C++ Primer"},
                                 {"Stanley B. Lippman", "Inside the C++ Object Model"},
                                 {"K&R",                "The C Programming Language"},
                                 {"Hal Abelson",        "Structure and Interpretation of Computer Programs"}};
    // 看来是不用 c.erase(k) 来删除 P.387，用的应该是 c.erase(p)
    removeByKey(m_i, "Stanley B. Lippman"); // 这里嫌麻烦就不写返回值了
    removeByKey(m_i, "K");
    for (const auto &item: m_i) {
        std::cout << "Author: " << item.first << ", book: " << item.second << std::endl;
    }
    return 0;
}