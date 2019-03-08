#pragma once
#include "Account.hpp"

class Checking_Account : public Account{
public:
    bool withdraw(double amount);
    Checking_Account(std::string name, double balance);
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);

};