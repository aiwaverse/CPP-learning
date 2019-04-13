#include "quicksort.hpp"

int main(){
    mei::sort_data<int> vec;
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(8);
    vec.push_back(2);    
    std::cout << vec;
    vec.quicksort(0,vec.size()-1);
    std::cout << vec;
    std::cout << "podo podohae" << std::endl;
    return 0;
}