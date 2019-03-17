#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <ciso646>
#include <climits>

class I_Printable{
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
    virtual void print(std::ostream& os) const = 0;
    virtual ~I_Printable();
};

class Account: public I_Printable{
protected:
    std::string owner;
    double balance;
public:
    Account(std::string name, double value);
    virtual ~Account();
};
class Savings_Account: public Account{
public:
    Savings_Account(std::string name, double value);
    virtual void print(std::ostream& os)const override;
    virtual ~Savings_Account();
};
