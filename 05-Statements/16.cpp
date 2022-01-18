#include <iostream>
#include <vector>

bool isPrefix(const std::vector<int> &fir_vec,const std::vector<int> &sec_vec) {
    if (fir_vec.size() > sec_vec.size()) {
        isPrefix(sec_vec, fir_vec);
    }
    for (decltype(fir_vec.size()) i = 0; i != fir_vec.size(); ++i) {
        if (fir_vec[i] != sec_vec[i]) return false;
    }
    return true;
}

int main() {
    std::vector<int> fir_vec{1, 2}, sec_vec{1, 2, 3, 4}, short_vec, long_vec;
    std::cout << (isPrefix(fir_vec, sec_vec) ? "是前缀" : "不是前缀") << std::endl;
    return 0;
}