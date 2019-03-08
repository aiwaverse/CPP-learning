#include "Account.hpp"

Account::Account() : Account(0.0) {}

Account::Account(double balance) : balance {balance}{}

void Account::deposit(double amount)
{
    balance+=amount;
}
void Account::withdraw(double amount)
{
    if(balance>=amount)
        balance-=amount;
    else
    {
        std::cout << "Insufficient funds" << std::endl;
    }
}
std::ostream &operator<<(std::ostream &os, const Account &acc)
{
    os << "Account balance: " << acc.balance << std::endl;
    return os;
}