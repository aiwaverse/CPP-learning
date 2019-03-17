#include "classes.hpp"

I_Printable::~I_Printable(){};
Account::~Account(){};
Savings_Account::~Savings_Account(){};
Account::Account(std::string name, double value) : owner{name}, balance{value}{};

Savings_Account::Savings_Account(std::string name, double value) : Account(name,value){};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
{
    obj.print(os);
    return os;
}

void Savings_Account::print(std::ostream &os) const
{
    os << "Savings account owned by: " << owner << "\nBalance: $" << balance << std::endl;
};