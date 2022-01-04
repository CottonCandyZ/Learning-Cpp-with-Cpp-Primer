#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::vector, std::string, std::cin, std::cout, std::endl;

int main() {
    vector<string> words;
    string input_word;
    while (cin >> input_word) {
        words.push_back(input_word);
    }

    for (auto &i : words) {
        for (auto &c : i) {
            c = std::toupper(c);
        }
    }

    for (auto i : words) {
        cout << i << endl;
    }

    return 0;
}