//
// Created by CottonCandyZ on 3/5/22.
//

#ifndef C__PRIMER_EMPLOYEE_2_H
#define C__PRIMER_EMPLOYEE_2_H

#include <string>

class Employee {
public:
    Employee() {
        id = ++id_gen;
    }
    Employee(const std::string &name) {
        this->name = name;
        id = ++id_gen;
    }
    Employee &operator=(const Employee& e) = delete;
    Employee(const Employee&) = delete;
private:
    unsigned id;
    inline static unsigned id_gen = 0;
    std::string name;
};



#endif //C__PRIMER_EMPLOYEE_2_H
