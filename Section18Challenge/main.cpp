#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "InsufficientFundsExpection.hpp"

using namespace std;

int main()
{
    // test your code here
    Savings_Account mimi{"Mimi", 5000, 4.5};
    std::cout << mimi << std::endl;
    try
    {
        Savings_Account luna{"Luna", -2500, 0.9};
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    try
    {
        mimi.withdraw(10000);
    }catch (const InsufficientFundsExpection &ex){
        std::cerr << ex.what() << std::endl;
    }
    Trust_Account aiwa {"Aiwa", 750, 10.0};
    aiwa.withdraw(100);
    aiwa.withdraw(100);
    aiwa.withdraw(100);
    std::cout << aiwa << std::endl;
    try{
        aiwa.withdraw(100);
    } catch(const InsufficientWithdraws &ex){
        std::cerr << ex.what() << std::endl;
    }


    std::cout << "Program completed successfully" << std::endl;
    return 0;
}
