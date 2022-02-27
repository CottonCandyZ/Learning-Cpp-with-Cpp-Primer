//
// Created by CottonCandyZ on 2/26/22.
//

#include <iostream>
#include <vector>
#include <map>
#include "../09-Sequential-Containers/51.h"

using std::map, std::vector, std::string;


bool addNewFamily(map<string, vector<std::pair<string, Date>>> &families, const string &family_name,
                  const vector<std::pair<string, Date>> &child) {
    if (families.find(family_name) == families.end()) { // 读到后面的章节可以发现，这里直接使用 insert 并判断其返回值也是可以的。
        families[family_name] = child;
        return true;
    }
    return false;
}

bool
addChild(map<string, vector<std::pair<string, Date>>> &families, const string &family_name, const string &child_name,
         const string &birthDate) {
    const auto &t = families.find(family_name);
    if (t != families.end()) {
        t->second.emplace_back(child_name, birthDate);
        return true;
    }
    return false;
}

int main() {
    map<string, vector<std::pair<string, Date>>> families;
    addNewFamily(families, "Cotton", {});
    addChild(families, "Cotton", "CandyZ", "4/10/1999");
    addChild(families, "Cotton", "CandyG", "9/15/2001");
    addNewFamily(families, "Zzj", {{"Zzt", Date("1/11/1999")}});
    for (const auto &item: families) {
        std::cout << item.first << " 家族，有孩子：";
        for (const auto &ch: item.second) {
            std::cout << ch.first << " 生日为 ";
            ch.second.print(std::cout) << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}