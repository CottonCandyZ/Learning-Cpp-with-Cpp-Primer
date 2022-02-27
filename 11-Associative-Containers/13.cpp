//
// Created by CottonCandyZ on 2/26/22.
//


#include <iostream>
#include <vector>

using std::string, std::cout, std::cin, std::vector, std::endl;

int main() {
    vector<std::pair<string, int>> vec_pair;
    string s_buf;
    int i_buf;
    while (cin >> s_buf >> i_buf) {
        vec_pair.emplace_back(s_buf, i_buf); // 这个最佳
//        vec_pair.push_back({s_buf, i_buf});
//        vec_pair.push_back(std::make_pair(s_buf, i_buf));
//        vec_pair.push_back(std::pair<string, int>(s_buf, i_buf));
    }
    for (const auto &item: vec_pair) {
        cout << item.first << " " << item.second << endl;
    }
    return 0;
}