#include <iostream>
#include <string>

using std::string;

void print_int(int a[]) {
    for (unsigned i = 0; i < 10; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void print_string(string a[]) {
    for (unsigned i = 0; i < 10; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

string sa[10];  // 全是空字符串
int ia[10];     // 全是 0

int main() {
    string sa2[10];  // 全是空字符串
    int ia2[10];     // 未定义的
    print_string(sa);
    print_int(ia);
    print_string(sa2);
    print_int(ia2);
    return 0;
}