#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <string>

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
