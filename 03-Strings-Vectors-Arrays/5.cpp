#include <iostream>
#include <string>

using std::string, std::cin, std::cout, std::endl;

int main() {
    string temp, sum, other_sum;
    while (cin >> temp) {
        sum += temp;
        other_sum += temp + " "; // 这样写最后会多一个空格
    }
    cout << sum << endl;
    cout << other_sum << endl;
    return 0;
}