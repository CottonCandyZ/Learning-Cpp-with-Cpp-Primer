#include <iostream>
#include <vector>

using std::vector, std::cin, std::cout;

int main() {
    vector<int> nums;
    int input;
    while (cin >> input)
        nums.push_back(input);
    for (auto it = nums.cbegin() + 1; it != nums.cend(); it++) {
        cout << *(it - 1) + *it << " ";
    }
    cout << std::endl;
    for (auto it_begin = nums.cbegin(), it_end = nums.cend() - 1; it_begin < it_end; it_begin++, it_end--) {
        cout << *it_begin + *it_end << " ";
    }
    if (nums.size() % 2 == 1)  // 奇数中间另外处理
        cout << nums[nums.size() / 2];
    cout << std::endl;

    return 0;
}