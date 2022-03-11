//
// Created by CottonCandyZ on 3/5/22.
//

#ifndef C__PRIMER_EMPLOYEE_1_H
#define C__PRIMER_EMPLOYEE_1_H

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
private:
    unsigned id;
    inline static unsigned id_gen = 0;
    std::string name;
};
#endif //C__PRIMER_EMPLOYEE_1_H
