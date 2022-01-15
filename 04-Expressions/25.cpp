#include <iostream>

int main() {
    std::bitset<32> q_bit(~'q' << 6);
    std::cout << q_bit << std::endl;
    std::cout << (~'q' << 6) << std::endl;
    return 0;
}