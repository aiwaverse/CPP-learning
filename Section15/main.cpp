#include "Account.hpp"
#include "Savings_Account.hpp"
#include "Checking_Account.hpp"

int main(void)
{
    Checking_Account carly {"Carly", 1000};
    std::cout << carly << std::endl;

    std::cout << "This program ended successfully";
    return 0;
}