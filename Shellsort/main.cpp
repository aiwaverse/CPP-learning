#include "shellsort.hpp"

int main(void)
{
    std::vector<int> vec_to_be_ordered{5, 893, 213, 23, 2, 67, 1435, 128937, 212};
/*    srand(time(nullptr));
    std::vector<int> vec_to_be_ordered {};
    for(int i{0};i<10000;++i)
        vec_to_be_ordered.push_back(rand());*/
    std::cout << "[ ";
    for (const auto &v : vec_to_be_ordered)
        std::cout << v << " ";
    std::cout << "]\n";
    shellsort(vec_to_be_ordered);
    std::cout << "[ ";
    for (const auto& v : vec_to_be_ordered)
        std::cout << v << " ";
    std::cout << "]\n";
    std::cout << "totally cool" << std::endl;
    return 0;
}