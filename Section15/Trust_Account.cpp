#include "Trust_Account.hpp"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate) : Savings_Account{name, balance, int_rate}, withdraws_already_done{0}
{
}
bool Trust_Account::deposit(double amount)
{
    if (amount >= bonus_threshold)
        amount += deposit_bonus;
    return Account::deposit(amount);
}
bool Trust_Account::withdraw(double amount)
{
    if ((withdraws_already_done < max_withdraws) and (amount <= balance * max_withdraw_percent))
    {
        withdraws_already_done++;
        return Savings_Account::withdraw(amount);
    }
    else
    {
        std::cout << ((withdraws_already_done >= max_withdraws)? "3 withdraws already one" : "You cant withdraw more than 20% of your balance") << std::endl;
        return false;
    }
}
std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}