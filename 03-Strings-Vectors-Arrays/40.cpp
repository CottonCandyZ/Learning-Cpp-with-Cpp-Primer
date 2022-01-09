#include <iostream>
#include <cstring>

int main() {
    char ca1[] = "Hello";
    char ca2[] = "Apple";
    
    size_t size = strlen(ca1) + strlen(ca2) + 1;
    char result[size];
    strcpy(result, ca1);
    strcat(result, ca2);

    std::cout << result << std::endl;

    return 0;
}
