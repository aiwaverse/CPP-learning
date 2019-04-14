#include "quicksort.hpp"

int main(){
    mei::sort_data<int> vec;
    vec.fill_random(15);
    std::cout << vec;
    vec.quicksort();
    std::cout << vec;
    vec.clear_all();
    std::cout << "===================\n";
    vec.fill_random(15);
    std::cout << vec;
    vec.random_quicksort();
    std::cout << vec;
    std::cout << "podo podohae" << std::endl;
    return 0;
}