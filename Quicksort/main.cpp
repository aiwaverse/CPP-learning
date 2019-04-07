#include "quicksort.hpp"

int main(void)
{
    srand(time(nullptr));
    std::vector<std::string> vec{"aiwa", "mimi", "carly", "luna", "mei"};
    /*const int vector_size {10};
    for(auto i{0};i < vector_size;++i)
    {
        vec.push_back((rand()%100)+1);
    }*/
    for(const auto& v: vec)
        std::cout << v << " ";
    std::cout << std::endl;
    long long base_zero {0};
    long long size = static_cast<long long int>(vec.size()-1);
    quicksort(vec, base_zero, size);
    for(const auto& v: vec)
        std::cout << v << " ";
    std::cout << std::endl;
    std::cout << "it works? it works" << std::endl;
    return 0;
}