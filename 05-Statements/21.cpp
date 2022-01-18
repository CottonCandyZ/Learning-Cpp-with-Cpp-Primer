#include <iostream>
#include <string>


using std::string, std::string, std::cin, std::cout, std::endl;

int main() {
    string input, pre = "";
    while (cin >> input) {
        if (!isupper(input[0])) continue; // 补一句这个就行
        if (input == pre) break;
        pre = input;
    }
    if (cin.eof())  // 判断是不是正常结束
        cout << "没有任何首字母大写的单词是连续重复出现的。" << endl;
    else
        cout << "重复出现的单词为: " << input << endl;
    return 0;
}