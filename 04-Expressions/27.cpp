#include <iostream>

using std::bitset, std::cout, std::endl;

void result (unsigned long ul) {
    bitset<32> ul_bit(ul);
    cout << ul_bit << endl << ul << endl << endl;
}

int main() {
    unsigned long ul1 = 3, ul2 = 7;
    result(ul1 & ul2);
    result(ul1 | ul2);
    result(ul1 && ul2);
    result(ul1 || ul2);

    return 0;
}