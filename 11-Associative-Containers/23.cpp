//
// Created by CottonCandyZ on 2/26/22.
//

#include <iostream>
#include <vector>
#include <map>
#include "../09-Sequential-Containers/51.h"

using std::multimap, std::vector, std::string;


bool addNewFamily(multimap<string, std::pair<string, Date>> &families, const string &family_name,
                  const vector<std::pair<string, Date>> &child) {
    if (families.find(family_name) == families.end()) {
        for (const auto &item: child) {
            families.emplace(family_name, item);
        }
        return true;
    }
    return false;
}

bool
addChild(multimap<string, std::pair<string, Date>> &families, const string &family_name, const string &child_name,
         const string &birthDate) {
    families.emplace(family_name, std::make_pair(child_name, Date(birthDate)));
    return false;
}

int main() {
    multimap<string, std::pair<string, Date>> families;
    addNewFamily(families, "Cotton", {{"CandyZ", Date("4/10/1999")}});
    addChild(families, "Cotton", "CandyG", "9/15/2001");
    addNewFamily(families, "Zzj", {{"Zzt", Date("1/11/1999")}});
    for (const auto &item: families) {
        std::cout << item.first << " 家族，有孩子：";
        std::cout << item.second.first << " 生日为 ";
        item.second.second.print(std::cout) << ", ";
        std::cout << std::endl;
    }

    return 0;
}