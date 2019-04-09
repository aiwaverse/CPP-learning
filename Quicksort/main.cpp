#include "quicksort.hpp"

int main(void)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::vector<int> vec{};
    const int vector_size{100000};
    std::uniform_int_distribution<long long> distribution(0, 1000);
    for (auto i{0}; i < vector_size; ++i)
    {
        vec.push_back(distribution(generator));
    }
    /*for (const auto &v : vec)
        std::cout << v << " ";
    std::cout << std::endl;*/
    long long base_zero{0};
    long long size = static_cast<long long int>(vec.size() - 1);
    auto time = calculate_time(vec, base_zero, size, random_quicksort);
    /*for (const auto &v : vec)
        std::cout << v << " ";
    std::cout << std::endl;*/
    std::cout << "quicksort took " << time << " microseconds" << std::endl;
    vec.clear();
    for (auto i{0}; i < vector_size; ++i)
    {
        vec.push_back(distribution(generator));
    }
    time = calculate_time(vec, shellsort_ciura_basic);
    std::cout << "shellsort took " << time << " microseconds" << std::endl;
    vec.clear();
    for (auto i{0}; i < vector_size; ++i)
    {
        vec.push_back(distribution(generator));
    }
    time = calculate_std_sort_time(vec);
    std::cout << "std::sort took " << time << " microseconds" << std::endl;
    vec.clear();
    for (auto i{0}; i < vector_size; ++i)
    {
        vec.push_back(distribution(generator));
    }
    time = calculate_std_stable_sort_time(vec);
    std::cout << "std::stable_sort took " << time << " microseconds" << std::endl;
    std::cout << "it works? it works" << std::endl;
    return 0;
}