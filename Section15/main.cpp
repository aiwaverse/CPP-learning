#include "Account.hpp"
#include "Savings_Account.hpp"
#include "Checking_Account.hpp"
#include "Trust_Account.hpp"

int main(void)
{
    Trust_Account carly {"Carly", 0,5};
    std::cout << carly << std::endl;
    carly.deposit(5000);
    std::cout << carly << std::endl;
    carly.withdraw(100);
    std::cout << carly << std::endl;
    carly.withdraw(100);
    std::cout << carly << std::endl;
    carly.withdraw(100);
    std::cout << carly << std::endl;
    carly.withdraw(100);
    std::cout << carly << std::endl;
    carly.withdraw(100);
    std::cout << carly << std::endl;
    std::cout << "This program ended successfully";
    return 0;
}