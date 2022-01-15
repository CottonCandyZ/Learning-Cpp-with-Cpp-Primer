#include <iostream>
using std::cout, std::endl;

int main() {
    cout << "int: " << sizeof(int) << endl
         << "short: " << sizeof(short) << endl
         << "unsigned: " << sizeof(unsigned) << endl
         << "long: " << sizeof(long) << endl
         << "long long: " << sizeof(long long) << endl
         << "char: " << sizeof(char) << endl
         << "bool: " << sizeof(bool) << endl
         << "int *: " << sizeof(int *) << endl
         << "double: " << sizeof(double) << endl
         << "float: " << sizeof(float) << endl
         << "long double: " << sizeof(long double) << endl;
    return 0;
}