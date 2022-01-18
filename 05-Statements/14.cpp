#include <iostream>
#include <string>

using std::cout, std::cin, std::string, std::endl;

int main() {
    string input, pre = "", output;
    int cnt = 1, max_cnt = 0;
    while (cin >> input) {
        if (input == pre){
            ++cnt;
            if (cnt > max_cnt) {
                max_cnt = cnt;
                output = input;
            }
        } else {
            cnt = 1;
        }
        pre = input;
    }
    if (max_cnt != 0) {
        cout << output << " repeats " << max_cnt << " times" << endl;
    } else {
        cout << "no repeat words.";
    }
    return 0;
}