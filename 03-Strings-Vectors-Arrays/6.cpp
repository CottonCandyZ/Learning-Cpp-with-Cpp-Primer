#include <cctype>
#include <iostream>
#include <string>

using std::cout, std::cin, std::endl, std::string, std::toupper;

int main() {
    string str;
    cin >> str;
    for (auto &c : str) {
        c = 'X';
    }
    cout << str << endl;

    return 0;
}