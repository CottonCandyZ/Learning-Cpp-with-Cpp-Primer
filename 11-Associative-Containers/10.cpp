//
// Created by CottonCandyZ on 2/25/22.
//

#include <iostream>
#include <map>
#include <string>
#include <list>
#include <vector>

using std::map, std::string, std::list, std::cin, std::vector;


int main() {
    map<vector<int>::iterator, int> v_mp;
    map<list<int>::iterator , int> l_mp;


    vector<int> vi;
    v_mp.insert(std::pair<std::vector<int>::iterator, int>(vi.begin(), 0)); // 这里用一对 pair 测试


//    std::list<int> li;
//    l_mp.insert(std::pair<std::list<int>::iterator, int>(li.begin(), 0)); // 无法编译

    return 0;
}