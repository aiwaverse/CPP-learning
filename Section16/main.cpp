#include "classes.hpp"

int main(void)
{  
    Savings_Account carly("Carly", 1000);
    Account& base = carly;
    std::cout << carly << std::endl;


    std::cout << "The program ended succesfully" <<std::endl;
    return 0;
}