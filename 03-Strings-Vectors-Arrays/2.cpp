#include <iostream>
#include <string>

using std::string, std::cin, std::cout, std::endl;

int main() {
    string line;
    getline(cin, line);
    cout << line << endl;

    string word;
    cin >> word;
    cout << word << endl;

    return 0;
}