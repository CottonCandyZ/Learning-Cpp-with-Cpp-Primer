#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo{""};
    unsigned units_sold{0};
    double revenue{0};
};

int main() {
    // {  // 20
    //     Sales_data book;

    //     while (std::cin >> book.bookNo >> book.units_sold >> book.revenue) {
    //         std::cout << book.bookNo << " "
    //                   << book.units_sold << " "
    //                   << book.units_sold * book.revenue << " "
    //                   << book.revenue << " " << std::endl;
    //     }
    // }

    // {  // 21
    //     Sales_data data1, data2;
    //     std::cin >> data1.bookNo >> data1.units_sold >> data1.revenue;
    //     std::cin >> data2.bookNo >> data2.units_sold >> data2.revenue;
    //     std::cout << data1.bookNo << " "
    //               << data1.units_sold + data2.units_sold << " "
    //               << data1.units_sold * data1.revenue + data2.units_sold * data2.revenue << " "
    //               << (data1.units_sold * data1.revenue + data2.units_sold * data2.revenue) / (data1.units_sold + data2.units_sold) << " "
    //               << std::endl;
    // }

    // { // 22
    //     Sales_data book;
    //     double sum_revenue;
    //     int sum_units_sold;
    //     while (std::cin >> book.bookNo >> book.units_sold >> book.revenue) {
    //         sum_units_sold += book.units_sold;
    //         sum_revenue += book.units_sold * book.revenue;
    //     }
    //     std::cout << book.bookNo << " "
    //     << sum_units_sold << " "
    //     << sum_revenue << " "
    //     << sum_revenue / sum_units_sold << std::endl;
    // }

    // {  // 23
    //     Sales_data currData, data;
    //     if (std::cin >> currData.bookNo >> currData.units_sold >> currData.revenue) {
    //         int cnt = 1;
    //         while (std::cin >> data.bookNo >> data.units_sold >> data.revenue) {
    //             if (data.bookNo == currData.bookNo) {
    //                 ++cnt;
    //             } else {
    //                 std::cout << currData.bookNo << " sales " << cnt << std::endl;
    //                 currData = data;
    //                 cnt = 1;
    //             }  // end else
    //         }      // end while
    //         std::cout << currData.bookNo << " sales " << cnt << std::endl;
    //     }  // end if
    // }

    {  // 25
        Sales_data total;
        if (std::cin >> total.bookNo >> total.units_sold >> total.revenue) {
            Sales_data trans;
            while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
                if (total.bookNo == trans.bookNo) {
                    total.units_sold += trans.units_sold;
                    total.revenue = (total.units_sold * total.revenue + trans.units_sold * trans.revenue) / (total.units_sold + trans.units_sold);
                } else {
                    std::cout << total.bookNo << " "
                              << total.units_sold << " "
                              << total.units_sold * total.revenue << " "
                              << total.revenue << " " << std::endl;
                    total = trans;
                }
            }
            std::cout << total.bookNo << " "
                      << total.units_sold << " "
                      << total.units_sold * total.revenue << " "
                      << total.revenue << " " << std::endl;
        } else {
            std::cerr << "No Data?!" << std::endl;
            return -1;
        }
    }

    return 0;
}