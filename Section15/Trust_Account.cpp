#include "Trust_Account.hpp"

int Trust_Account::withdraws_already_done=0;
Trust_Account::Trust_Account(std::string name, double balance, double int_rate) : Savings_Account{name, balance, int_rate}
{
}
bool Trust_Account::deposit(double amount)
{
    const double value_to_give_bonus{5000}, bonus_to_give{50};
    if (amount >= value_to_give_bonus)
        amount += bonus_to_give;
    return Savings_Account::deposit(amount);
}
bool Trust_Account::withdraw(double amount)
{
    const int max_withdraws {3};
    if (withdraws_already_done < max_withdraws or (amount > balance * 0.2))
    {
        withdraws_already_done++;
        return Savings_Account::withdraw(amount);
    }
    else
    {
        std::cout << "Error, you already did 4 withdraws" << std::endl;
        return false;
    }
}
std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}