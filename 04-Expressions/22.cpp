#include <iostream>

int main() {
    int grade;
    std::cin >> grade;
    auto final_grade = (grade > 90)   ? "high pass"
                       : (grade < 60) ? "fail"
                       : (grade > 75) ? "low pass"
                                      : "pass";

    if (grade > 90) {
        final_grade = "high pass";
    } else if (grade > 75) {
        final_grade = "low pass";
    } else if (grade > 60) {
        final_grade = "pass";
    } else {
        final_grade = "fail";
    }
    std::cout << final_grade << std::endl;
    return 0;
}