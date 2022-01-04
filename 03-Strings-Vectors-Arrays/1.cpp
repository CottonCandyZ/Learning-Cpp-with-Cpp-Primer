#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
    {// 1.9
        int i = 50, sum = 0;
        while (i <= 100) {
            sum += i++;
        }
        cout << sum << endl;
    }

    { // 1.10
        int i = 10;
        while (i >= 0) {
            cout << i-- << " ";
        }
        cout << endl;
    }

    { // 1.11
        int begin, end;
        cin >> begin >> end;
        if (begin > end) {
            while (begin >= end) {
                cout << begin-- << " ";
            }
        } else {
            while (begin <= end) {
                cout << begin++ << " ";
            }
        }
        cout << endl;
    }

    { // 2.41 略

    }

    return 0;
}