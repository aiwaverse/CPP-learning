#pragma once
#include "Savings_Account.hpp"

class Trust_Account : public Savings_Account{
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
//For next time, instead of just static, use static constexpr, that should make things easier
//Also, create constants HERE, not on the member functions, so it's easy to change if needed
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate  = 0.0;
    static constexpr double deposit_bonus = 50.0;
    static constexpr double bonus_threshold = 5000.0;
    static constexpr int max_withdraws = 3;
    static constexpr double max_withdraw_percent = 0.2;
protected:
    int withdraws_already_done;
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    // Deposits of $5000.00 or more will receive $50 bonus
    bool deposit(double amount);
    // Only allowed maximum of 3 withdrawals, each can be up to a maximum of 20% of the account's value
    bool withdraw(double amount);

};