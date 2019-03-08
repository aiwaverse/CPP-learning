#pragma once
#include "Savings_Account.hpp"

class Trust_Account : public Savings_Account{
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
//For next time, instead of just static, use static constexpr, that should make things easier
//Also, create constants HERE, not on the member functions, so it's easy to change if needed
protected:
    static int withdraws_already_done;
public:
    Trust_Account(std::string name, double balance, double int_rate);
    bool deposit(double amount);
    bool withdraw(double amount);

};