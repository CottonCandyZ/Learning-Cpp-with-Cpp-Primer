#include <iostream>
#include <string>

using std::cin, std::cout, std::string, std::endl;

int main() {
    string input_1, input_2, rsp;
    do {
        cout << "输入两个字符串: ";
        cin >> input_1 >> input_2;
        cout << "较短的一个是 " << (input_1.length() <= input_2.length() ? input_1 : input_2) << endl
        << "是否继续输入？输入 yes or no: ";
        cin >> rsp;
    } while (!rsp.empty() && rsp[0] != 'n');

    return 0;
}