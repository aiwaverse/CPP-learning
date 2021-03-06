#pragma once
#include "Account.hpp"

class Checking_Account : public Account{
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;
public:
    bool withdraw(double amount);
    Checking_Account(std::string name = def_name, double balance = def_balance);
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);

};