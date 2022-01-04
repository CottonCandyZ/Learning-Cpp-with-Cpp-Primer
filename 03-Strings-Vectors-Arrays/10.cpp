#include <cctype>
#include <iostream>
#include <string>

using std::cout, std::cin, std::endl, std::string;

int main() {
    string str;
    cin >> str;
    for (auto c : str) {
        if (!std::ispunct(c)) {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}