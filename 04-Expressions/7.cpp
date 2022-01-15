#include <iostream>

using std::cout, std::endl;

int main() {
    int i = -1;
    unsigned u_i = 0;
    cout << "--u_i:" << --u_i << endl; // unsigned 负溢
    cout << "++u_i: " << ++u_i << endl; // unsigned 正溢
    i <<= (sizeof(i) * 8 - 1);
    cout << "i: " << i << endl; // B1000...0
    cout << "i - 1: " << i - 1 << endl; // sigend 负溢

    return 0;
}