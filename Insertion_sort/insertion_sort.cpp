#include <iostream>
#include <vector>
#include <ciso646>
#include <ctime>
#include "sort.hpp"

int main(void)
{
    srand(time(nullptr));
    std::vector<int> vec { 8, 2,  7, 4 , 3, 0};
 //   const size_t max_vector_size {30};
 //   for(auto i{0};i<max_vector_size;++i)
 //      vec.push_back(rand()%100);      //fills the vector with 30 random numbers
    auto count_of_operations = insertion_sort(vec);
    std::cout << "[ ";
    for(auto const& v:vec)
        std::cout << v << ' ';
    std::cout << ']' << std::endl;
    std::cout << "operations: " << count_of_operations << std::endl;
    std::cout << "The program has ended totally fine, giiiirl" << std::endl;
    return 0;
}