#include <vector>

using std::vector;

int main() {
    vector<int> nums1(10, 42); // 显然这个最好
    vector<int> nums2;
    for (decltype(nums2.size()) i = 0; i < 10; i++) {
        nums2.push_back(42);
    }

    vector<int> nums3(10);
    for (auto &i : nums3) {
        i = 42;
    }

    return 0;
}