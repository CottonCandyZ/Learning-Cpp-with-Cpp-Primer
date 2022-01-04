#include <iostream>
#include <vector>

using std::vector, std::cin, std::cout;

int main() {
    vector<int> nums;
    int input;
    while (cin >> input)
        nums.push_back(input);
    for (decltype(nums.size()) i = 1; i < nums.size(); i++) {
        cout << nums[i - 1] + nums[i] << " ";
    }
    cout << std::endl;
    for (decltype(nums.size()) i = 0; i < nums.size() / 2; i++) {
        cout << nums[i] + nums[nums.size() - 1 - i] << " ";
    }
    if (nums.size() % 2 == 1) // 奇数中间另外处理
        cout << nums[nums.size() / 2];
    cout << std::endl;

    return 0;
}