//
// Created by CottonCandyZ on 2/28/22.
//


#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>

using std::ifstream, std::unordered_map, std::string, std::cout, std::endl;

unordered_map<string, string> buildMap(ifstream &unordered_map_file) {
    unordered_map<string, string> trans_unordered_map;
    string key;
    string value;
    while (unordered_map_file >> key && getline(unordered_map_file, value))
        if (value.size() > 1)
            trans_unordered_map[key] = value.substr(1);
        else
            throw std::runtime_error("no rule for " + key);
    return trans_unordered_map;
}

const string &transform(const string &s, const unordered_map<string, string> &m) {
    auto unordered_map_it = m.find(s);
    if (unordered_map_it != m.cend())
        return unordered_map_it->second;
    else
        return s;
}

void word_transform(ifstream &unordered_map_file, ifstream &input) {
    auto trans_unordered_map = buildMap(unordered_map_file);
    string text;
    while (getline(input, text)) {
        std::istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word) {
            if (firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word, trans_unordered_map);
        }
        cout << endl;
    }
}


int main() {
    ifstream unordered_map_file("../unordered_map_file");
    ifstream input_file("../input_file");
    word_transform(unordered_map_file, input_file);
    return 0;
}