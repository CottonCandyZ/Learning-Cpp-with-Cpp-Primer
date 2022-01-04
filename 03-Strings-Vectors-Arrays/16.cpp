#include <iostream>
#include <string>
#include <vector>

using std::vector, std::string, std::cout, std::endl;

int main() {
    vector<int> v1;
    vector<int> v2(10);           // 10 个元素，均为默认值
    vector<int> v3(10, 42);       // 10 一个元素
    vector<int> v4{10};           // 一个元素 10
    vector<int> v5{10, 42};       // 10 42 两个元素
    vector<string> v6{10};        // 10 个空的字符串
    vector<string> v7{10, "hi"};  // 10 个 hi

    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 content: ";
    for (auto i : v1) {
        cout << i << " ";
    }
    cout << endl;

    cout << "v2 size: " << v2.size() << endl;
    cout << "v2 content: ";
    for (auto i : v2) {
        cout << i << " ";
    }
    cout << endl;

    cout << "v3 size: " << v3.size() << endl;
    cout << "v3 content: ";
    for (auto i : v3) {
        cout << i << " ";
    }
    cout << endl;

    cout << "v4 size: " << v4.size() << endl;
    cout << "v4 content: ";
    for (auto i : v4) {
        cout << i << " ";
    }
    cout << endl;

    cout << "v5 size: " << v5.size() << endl;
    cout << "v5 content: ";
    for (auto i : v5) {
        cout << i << " ";
    }
    cout << endl;

    cout << "v6 size: " << v6.size() << endl;
    cout << "v6 content: ";
    for (auto i : v6) {
        cout << i << " ";
    }
    cout << endl;

    cout << "v7 size: " << v7.size() << endl;
    cout << "v7 content: ";
    for (auto i : v7) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}