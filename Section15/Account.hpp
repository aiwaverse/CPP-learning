#pragma once
#include <iostream>
#include <vector>
#include <string>

class Account{
    friend std::ostream &operator<<(std::ostream &os, const Account &acc); //overloaded display 
protected:
    double balance;
public:
    Account();
    Account(double balance);
    void deposit (double amount);
    void withdraw(double amount);
};