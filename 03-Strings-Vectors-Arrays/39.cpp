#include <cstring>
#include <iostream>
#include <string>

using std::cout, std::endl;

int main() {
    std::string str1("Hello"), str2("Apple");
    cout << ((str1 == str2) ? "str1 == str2" : (str1 > str2 ? "str1 > str2" : "str1 < str2")) << endl;

    char *ch_str1 = "Hello", *ch_str2 = "Apple";
    int result = strcmp(ch_str1, ch_str2);
    cout << ((result == 0) ? "ch_str1 == ch_str2" : (result > 0 ? "ch_str1 > ch_str2" : "ch_str1 < ch_str2")) << endl;

    return 0;
}