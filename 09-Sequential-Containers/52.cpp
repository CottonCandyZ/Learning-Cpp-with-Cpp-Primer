//
// Created by CottonCandyZ on 2/20/22.
//

#include <iostream>
#include <stack>
#include <string>

using std::cin, std::cout, std::string, std::stack, std::endl;

int main() {
    string buf;
    stack<char> signs;
    stack<int> nums;
    cin >> buf;
    for (string::size_type p = 0; p != buf.size(); p++) {
        if (std::isdigit(buf[p])) {
            auto pos_before_num = buf.find_first_not_of("0123456789", p);
            auto num_len = pos_before_num - p;
            nums.push(std::stoi(buf.substr(p, pos_before_num)));
            p += num_len - 1;
        } else if (buf[p] == ')') {
            auto sign = signs.top();
            signs.pop();
            if (signs.top() != '(') {
                cout << "括号不匹配" << std::endl;
                break;
            }
            signs.pop();
            auto r = nums.top();
            nums.pop();
            auto l = nums.top();
            nums.pop();
            switch (sign) {
                case '+':
                    nums.push(r + l);
                    break;
                case '-':
                    nums.push(r - l);
                    break;
                case '*':
                    nums.push(r * l);
                    break;
                case '/':
                    nums.push(r / l);
                    break;
                default:
                    std::cout << "符号错误" << std::endl;
            }
            if (signs.empty()) {
                cout << "结果："<< nums.top() << endl;
            }
        } else {
            signs.push(buf[p]);
        }
    }

    return 0;
}