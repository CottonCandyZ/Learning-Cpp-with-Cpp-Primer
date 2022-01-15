#include <iostream>

using std::cout, std::endl;

int main() {
    cout << -30 * 3 + 21 / 5 << endl // -86
    << -30 + 3 * 21 / 6 << endl // -20
    << 30 / 3 * 21 % 5 << endl // 0
    << -30 / 3 * 21 % 4 << endl; //  -2
    return 0;
}