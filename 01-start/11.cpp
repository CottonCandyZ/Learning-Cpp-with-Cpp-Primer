#include <iostream>
int main() {
    int begin, end;
    std::cin >> begin >> end;
    while (begin <= end) {
        std::cout << begin << " ";
        begin++;
    }
    std::cout << std::endl;
    return 0;
}