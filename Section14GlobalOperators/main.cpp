#include <iostream>
#include <vector>
#include <string>
#include "Mystringglobal.hpp"

int main(void)
{
    std::cout << std::boolalpha;
    Mystring aiwa{" aiwa"};
    Mystring carly{"carly"};
    Mystring mimi{"mimi"};
    Mystring anxiety {"anxiety"};
//    std::cout << (aiwa==mimi) << std::endl;
//    std::cout << (aiwa!=mimi) << std::endl;
//    std::cout << (mimi > anxiety) << std::endl;
    std::cout << mimi << std::endl;
    mimi*=3;
    std::cout << mimi << std::endl;
    mimi++;
    std::cout << mimi << std::endl;
    --mimi;
    std::cout << mimi <<std::endl;

    std::cout << "This program ended successfully";
    return 0;
}