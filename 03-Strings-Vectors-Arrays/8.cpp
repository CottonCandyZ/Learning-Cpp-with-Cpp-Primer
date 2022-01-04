#include <cctype>
#include <iostream>
#include <string>

using std::cout, std::cin, std::endl, std::string, std::toupper;

int main() {
    string str;
    cin >> str;
    for (decltype(str.size()) i = 0; i < str.size(); i++) {
        str[i] = 'X';
    }

    decltype(str.size()) i = 0;
    while (i < str.size()) {
        str[i++] = 'X';
    }

    cout << str << endl;

    return 0;
}