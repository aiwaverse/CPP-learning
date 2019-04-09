#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <ctime>
#include <string>
#include <algorithm>

template <typename T1>
long long partition(std::vector<T1> &vector_to_be_partitioned, long long low, long long high)
{
    T1 pivot{vector_to_be_partitioned.at((low + high) / 2)}; //asign to pivot the member of vector[(low+high)/2]
    long long i{low - 1};
    long long j{high + 1};
    while (true)
    {
        do
        {
            ++i;
        } while (vector_to_be_partitioned.at(i) < pivot);
        do
        {
            --j;
        } while (vector_to_be_partitioned.at(j) > pivot);
        if (i >= j)
            return j;
        std::swap(vector_to_be_partitioned.at(i), vector_to_be_partitioned.at(j));
    }
}
template <typename T>
long long random_partition(std::vector<T>& vec, long long low, long long high)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<long long> distribution(low+1, high-1);
    auto r {distribution(generator)};
    std::swap(vec.at(low), vec.at(r));
    return partition(vec, low, high);
}

template <typename T1> //generic programming bc why not?
void quicksort(std::vector<T1> &vector_to_be_ordered, long long low, long long high)
{
    if (low < high)
    {
        long long p = partition(vector_to_be_ordered, low, high);
        quicksort(vector_to_be_ordered, low, p);
        quicksort(vector_to_be_ordered, p + 1, high);
    }
}
template <typename T>
void random_quicksort(std::vector<T>& vec, long long low, long long high)
{
    if(high>low)
    {
        auto p = random_partition(vec, low, high);
        quicksort(vec, low, p);
        quicksort(vec, p+1, high);
    }
}
template <typename T>
size_t calculate_time(std::vector<T> &vec, long long low, long long high, void (*sort)(std::vector<T> &, long long low, long long high)) //using a function pointer HOORAY
{
    auto start = std::chrono::high_resolution_clock::now();
    sort(vec, low, high); //cute
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); //but it just calculates run time
    return duration.count();
}
template <typename T>
size_t calculate_time(std::vector<T> &vec, void (*sort)(std::vector<T> &)) //using a function pointer HOORAY
{
    auto start = std::chrono::high_resolution_clock::now();
    sort(vec); //cute
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); //but it just calculates run time
    return duration.count();
}
void shellsort_ciura_basic(std::vector<int> &vec)
{
    std::vector<int> gap_list{1750, 701, 301, 132, 57, 23, 10, 4, 1}; //ciura's optimal list
    while (static_cast<int>(vec.size()) >= gap_list.at(0))
    {
        int element = floor(gap_list.at(0) * 2.25);
        gap_list.insert(gap_list.begin(), element);
    }
    for (auto gap : gap_list)
    {
        for (long unsigned i{static_cast<long unsigned>(gap)}; i < vec.size(); ++i) //cicyles the vector, starting at gap
        {
            int j{};
            int temp = vec.at(i);
            for (j = i; j >= gap and vec[j - gap] > temp; j -= gap)
            {
                vec.at(j) = vec.at(j - gap);
            }
            vec.at(j) = temp;
        }
    }
}
template <typename T>
size_t calculate_std_sort_time(std::vector<T> &vec)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(vec.begin(),vec.end());
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); //but it just calculates run time
    return duration.count();
}
template <typename T>
size_t calculate_std_stable_sort_time(std::vector<T> &vec)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::stable_sort(vec.begin(),vec.end());
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); //but it just calculates run time
    return duration.count();
}