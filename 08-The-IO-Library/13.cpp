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

bool valid(const std::string &str) {
    return isdigit(str[0]);
}

std::string format(const std::string &str) {
    return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

bool inputFromFile(const std::string &file_name, std::vector<PersonInfo> &people) {
    std::fstream input(file_name);
    if (!input) {
        return false;
    }
    std::string line, word;
    std::istringstream record;
    while (getline(input, line)) {
        PersonInfo info;
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        record.clear();
        people.push_back(info);
    }
    return true;
}

void output(std::ostream &os, const std::vector<PersonInfo> &people) {
    for (const auto &entry: people) {
        std::ostringstream formatted, badNums;
        for (const auto &nums: entry.phones) {
            if (!valid(nums)) {
                badNums << " " << nums;
            } else
                formatted << " " << format(nums);
        }
        if (badNums.str().empty()) {
            os << entry.name << " " << formatted.str() << std::endl;
        } else {
            std::cerr << "input error: " << entry.name << " invalid number(s) "
                      << badNums.str() << std::endl;
        }
    }
}

int main() {
    std::vector<PersonInfo> vec;
    inputFromFile("../08-The-IO-Library/input_11", vec);
    output(std::cout, vec);
    return 0;
}