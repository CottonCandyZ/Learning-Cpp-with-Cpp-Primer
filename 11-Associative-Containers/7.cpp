//
// Created by CottonCandyZ on 2/25/22.
//

#include <iostream>
#include <vector>
#include <map>
using std::map, std::vector, std::string;


bool addNewFamily(map<string, vector<string>> &families, const string &family_name, const vector<string> &child_name) {
    if (families.find(family_name) == families.end()) {
        families[family_name] = child_name;
        return true;
    }
    return false;
}

bool addChild(map<string, vector<string>> &families, const string &family_name, const string &child_name) {
    const auto &t = families.find(family_name);
    if (t != families.end()) {
        t->second.push_back(child_name);
        return true;
    }
    return false;
}

int main() {
    map<string, vector<string>> families;
    addNewFamily(families, "Cotton", {});
    addChild(families, "Cotton", "CandyZ");
    addChild(families, "Cotton", "CandyG");
    addNewFamily(families, "Zzj", {"Zzt"});
    for (const auto &item: families) {
        std::cout << item.first << " 家族，有孩子：";
        for (const auto &ch:item.second) {
            std::cout << ch << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}