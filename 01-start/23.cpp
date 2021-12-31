#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item currItem, item;

    if (std::cin >> currItem) {
        int cnt = 1;
        while (std::cin >> item) {
            if (item.isbn() == currItem.isbn()) {
                ++cnt;
            } else {
                std::cout << currItem.isbn() << " sales " << cnt << std::endl;
                currItem = item;
                cnt = 1;
            }  // end else
        } // end while
        std::cout << currItem.isbn() << " sales " << cnt << std::endl;
    }  // end if
    return 0;
}