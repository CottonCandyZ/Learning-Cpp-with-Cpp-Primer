//
// Created by CottonCandyZ on 3/18/22.
//

#include <string>
template <typename T> int compare(const T &v1, const T &v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int main() {
    compare<std::string>("c1", "c2");
    return 0;
}