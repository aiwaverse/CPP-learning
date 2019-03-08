#include "Account.hpp"
#include "Savings_Account.hpp"

int main(void)
{
    Account aiwas_account {100};
    std::cout << aiwas_account;
    Savings_Account aiwa_new_acc {200.0, 5};
    std::cout << aiwa_new_acc;
    aiwa_new_acc.deposit(1000);
    std::cout << aiwa_new_acc;


    std::cout << "This program ended successfully";
    return 0;
}