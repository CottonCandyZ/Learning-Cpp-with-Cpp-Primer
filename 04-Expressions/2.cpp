#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    *(vec.begin()); // *vec.begin()
    (*(vec.begin())) + 1; // *vec.begin() + 1
    return 0;
}