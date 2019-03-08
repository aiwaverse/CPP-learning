#include "Checking_Account.hpp"

Checking_Account::Checking_Account(std::string name, double balance): Account{name, balance}{}

bool Checking_Account::withdraw(double amount){
    return Account::withdraw(amount+1.5);
}
std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking Account: " << account.name << ": " << account.balance << "]";
    return os;
}