//
// Created by CottonCandyZ on 2/21/22.
//

#include <iostream>
#include <vector>
#include <functional>

using std::cin, std::cout, std::string, std::vector, std::endl;
using namespace std::placeholders;

bool check_size(const int &i, const string &str) {
    return i > str.length();
}

int main() {
    string str;
    cin >> str;
    vector<int> vec{1,3,5,6,7,9,10,12};
    auto found = std::find_if(vec.begin(), vec.end(),
                              std::bind(check_size, _1, str));
    if (found == vec.end()) {
        cout << "没找到。" << endl;
    } else {
        cout << *found << endl;
    }
    return 0;
}