// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"


int main() {

    Account* p1 = new Savings_Account{"Carly", 5000, 5};
    Account* p2 = new Checking_Account{"Mimi", 9000};
    Account* p3 = new Trust_Account{"Aiwa", 1000};
    Account* p4 = new Trust_Account{"Belle", 12000, 10};
    std::vector<Account *> acc_pointers {};
    acc_pointers.push_back(p1);
    acc_pointers.push_back(p2);
    acc_pointers.push_back(p3);
    acc_pointers.push_back(p4);
    display(acc_pointers);
    deposit(acc_pointers, 500);
    display(acc_pointers);
    for(size_t i {0};i<3;++i)
        withdraw(acc_pointers, 10);
    withdraw(acc_pointers, 10);
    delete p1;
    delete p2;
    delete p3;


    std::cout << "This program has ended sucefully" << std::endl;
    return 0;
}

