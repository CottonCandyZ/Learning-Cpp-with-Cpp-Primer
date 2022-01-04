#include <cctype>
#include <iostream>
#include <string>

using std::cout, std::cin, std::endl, std::string, std::toupper;

int main() {
    string str;
    cin >> str;
    for (char &c : str) { // char c 不行，char &c ok
        c = 'X';
    }
    cout << str << endl;

    return 0;
}