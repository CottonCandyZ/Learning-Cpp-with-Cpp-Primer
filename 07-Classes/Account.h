//
// Created by CottonCandyZ on 2/16/22.
//

#ifndef C__PRIMER_ACCOUNT_H
#define C__PRIMER_ACCOUNT_H

#include <string>


class Account {
public:
    void calculate() { amount += amount * interestRate; }

    static double rate() { return interestRate; }

    static void rate(double);

private:
    std::string owner;
    double amount;
    static double interestRate;
    static constexpr double todayRate = 42.42;
    static double initRate() { return todayRate; }
};

void Account::rate(double newRate) {
    interestRate = newRate;
}

double Account::interestRate = initRate();


#endif //C__PRIMER_ACCOUNT_H
