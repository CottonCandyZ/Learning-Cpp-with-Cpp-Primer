#include <iostream>

int main() {
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while (*cp) {
        // print 出来的不一定仅仅是 hello，由于其最后一个元素后指针所指地址的内容不一定是 0，所以其结果也是不确定的
        std::cout << *cp << std::endl;
        ++cp;
    }
    return 0;
}