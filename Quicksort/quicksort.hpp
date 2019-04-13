#pragma once
#include <algorithm>
#include <array>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

unsigned swaps{0}, recursives{0};

template <typename T>
T median_partition(std::vector<T>& vec, long long high, long long low) {
    std::array<T, 3> for_the_median{vec.at(low), vec.at(high), vec.at((high + low)/2)};
    std::sort(for_the_median.begin(), for_the_median.end());
    return for_the_median.at(for_the_median.size()/2);
}

template <typename T>
long long partition(std::vector<T>& vector_to_be_partitioned, long long high, long long low, bool flag) {
    // this functions calculates partitions for quickosrt, it defines the pivot to the floor division of the mean of the boundaries
    T pivot;
    if (flag == true)
        pivot = vector_to_be_partitioned.at(low);  // asign to pivot the member of vector[low]
    else
        pivot = median_partition(vector_to_be_partitioned, high, low);
    long long i{low - 1};
    long long j{high + 1};
    while (true) {
        do {
            ++i;
        } while (vector_to_be_partitioned.at(i) < pivot);
        do {
            --j;
        } while (vector_to_be_partitioned.at(j) > pivot);
        if (i >= j)
            return j;
        std::swap(vector_to_be_partitioned.at(i), vector_to_be_partitioned.at(j));
        swaps++;
    }
}
template <typename T>
long long random_partition(std::vector<T>& vec, long long high, long long low) {
    /*this function is to be used with the random version, it swaps the first element
with a random placed element, and then calls partition */
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<long long> distribution(low + 1, high);
    auto r{distribution(generator)};
    std::swap(vec.at(low), vec.at(r));
    return partition(vec, high, low, true);
}

template <typename T>
void quicksort(std::vector<T>& vector_to_be_ordered, long long high, long long low = 0) {
    // normal quicksort function
    if (low < high) {
        long long p = partition(vector_to_be_ordered, high, low, false);
        quicksort(vector_to_be_ordered, p, low);
        ++recursives;
        quicksort(vector_to_be_ordered, high, p + 1);
        ++recursives;
    }
}
template <typename T>
void random_quicksort(std::vector<T>& vec, long long low) {
    // quicksort but does with the random partitions, high is defined on the body to use with the calculate_time function
    long long high = vec.size() - 1;
    if (high > low) {
        auto p = random_partition(vec, high, low);
        quicksort(vec, p, low);
        quicksort(vec, high, p + 1);
    }
}
template <typename T>
size_t calculate_time(std::vector<T>& vec, void (*sort)(std::vector<T>&)) {
    // using a function pointer to calculate execution time of a function, returning in microseconds
    // can be changed to nanoseconds if wished
    auto start = std::chrono::high_resolution_clock::now();
    sort(vec);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    return duration.count();
}

// overloaded both the quicksort functions
// this is here so we can call it on the calculate_time function
// since that function only accepts a void function with a reference to a vector as parameter
template <typename T>
void quicksort(std::vector<T>& vec) { quicksort(vec, vec.size() - 1); }
template <typename T>
void random_quicksort(std::vector<T>& vec) { random_quicksort(vec, 0); }

template <typename T>
void shellsort_ciura_basic(std::vector<T>& vec) {
    // same normal shellsort program, but with templates to fit the idea
    std::vector<int> gap_list{1750, 701, 301, 132, 57, 23, 10, 4, 1};  // ciura's optimal list
    while (static_cast<int>(vec.size()) >= gap_list.at(0)) {
        int element = floor(gap_list.at(0) * 2.25);
        gap_list.push_back(element);
        std::rotate(gap_list.rbegin(), gap_list.rbegin() + 1, gap_list.rend());
    }
    for (auto gap : gap_list) {
        for (long unsigned i{static_cast<long unsigned>(gap)}; i < vec.size(); ++i)  // cicyles the vector, starting at gap
        {
            int j{};
            T temp = vec.at(i);
            for (j = i; j >= gap and vec[j - gap] > temp; j -= gap) {
                vec.at(j) = vec.at(j - gap);
            }
            vec.at(j) = temp;
        }
    }
}
