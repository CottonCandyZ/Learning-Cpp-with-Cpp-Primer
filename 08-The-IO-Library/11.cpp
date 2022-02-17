//
// Created by CottonCandyZ on 2/17/22.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

int main() {
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;
    while (getline(std::cin, line)) {
        PersonInfo info;
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        record.clear();
        people.push_back(info);
    }

    for (const auto &i: people) {
        std::cout << i.name;
        for (const auto &phone: i.phones) {
            std::cout <<  " " << phone;
        }
        std::cout << std::endl;
    }
    return 0;
}