#include <iostream>
#include <string>

struct Sales_data
{
    std::string bookNo{""};
    unsigned units_sold{0};
    double revenue{0};
};


int main() {
    Sales_data temp;
    std::cout << temp.bookNo << std::endl;
    return 0;
}