//
// Created by CottonCandyZ on 2/20/22.
//

#ifndef C__PRIMER_51_H
#define C__PRIMER_51_H

#include <string>
#include <array>
#include <iostream>

class Date {
public:
    unsigned year = 1970;
    unsigned month = 1;
    unsigned day = 1;

    Date() = default;

    explicit Date(const std::string &input);

    std::ostream &print(std::ostream &os) const {
        os << year << '-' << month << '-' << day;
        return os;
    }

private:
    std::array<std::string, 12> month_names{"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    unsigned getMonthFromName(const std::string &str);
};

Date::Date(const std::string &input) {
    std::string delimiters{" ,/"};
    auto month_day_delim_pos = input.find_first_of(delimiters);
    if (month_day_delim_pos == std::string::npos)
        throw std::invalid_argument("This format is not supported now.");
    if ((month = getMonthFromName(input.substr(0, month_day_delim_pos))) == 0)
        throw std::invalid_argument("Could not found a matching month.");
    auto day_year_delim_pos = input.find_first_of(delimiters, month_day_delim_pos + 1);
    day = std::stoi(input.substr(month_day_delim_pos + 1, day_year_delim_pos - month_day_delim_pos - 1));
    year = std::stoi(input.substr(day_year_delim_pos + 1));
}

unsigned Date::getMonthFromName(const std::string &str) {
    if (std::isdigit(str[0])) return std::stoi(str);
    for (size_t i = 0; i != 12; ++i) {
        if (str.find(month_names[i]) != std::string::npos) return i + 1;
    }
    return 0;
}


#endif //C__PRIMER_51_H
