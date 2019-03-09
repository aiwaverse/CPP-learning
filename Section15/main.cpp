#include "Account.hpp"
#include "Savings_Account.hpp"
#include "Checking_Account.hpp"
#include "Trust_Account.hpp"

int main(void)
{
    Checking_Account carly {"Carly", 0};
    carly.deposit(5000);
    std::cout << "After deposit: " << carly << std::endl;
    carly.withdraw(1000);
    std::cout << "After withdraw: " << carly << std::endl;

    std::cout << "This program ended successfully";
    return 0;
}