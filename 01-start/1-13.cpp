#include <iostream>
int main() {
    int sum = 0;

    // 1.9
    for (int i = 50; i <= 100; i++) {
        sum += i;
    }
    std::cout << sum << std::endl;

    // 1.10
    for (int i = 10; i >= 0; i--) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // 1.11
    int start, end;
    std::cin >> start >> end;
    for (; start <= end; start++) {
        std::cout << start << " ";
    }
    std::cout << std::endl;

    return 0;
}