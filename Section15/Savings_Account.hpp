#pragma once
#include "Account.hpp"

class Savings_Account: public Account{
    friend std::ostream &operator<<(std::ostream &os, const Savings_Account &sav_acc);
protected:
    double int_rate;
public:
    Savings_Account();
    Savings_Account(double balance, double int_rate);
    void deposit(double amount);
    //withdraw is inherited
};