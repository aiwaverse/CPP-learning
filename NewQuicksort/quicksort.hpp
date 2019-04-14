#include <algorithm>
#include <array>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <cctype>
#include "ind_functions.hpp"

namespace mei {
template <typename Sort_T>
class sort_data {
    //THIS TOOK AWHILE Y'KNOW
    template <typename T>
    friend std::ostream& operator<<(std::ostream& os, const sort_data<T>& rhs);

   private:
    std::vector<Sort_T> data{};
    long long recursions{};
    long long swaps{};
    void pivot_median(long long low, long long high);
    void random_pivot(long long low, long long high);
    long long partition(long long low, long long high);
    void quicksort(long long low, long long high);
    int64_t calculate_time(long long low, long long high);

   public:
    sort_data() : data{}, recursions{}, swaps{} {};
    void fill_random(size_t amount);
    void push_back(Sort_T n) {
        data.push_back(n);
    }
    int64_t quicksort();
    int64_t random_quicksort();
    void clear();
    void reset_counters();
    void clear_all();
    size_t size() { return data.size(); };
};
template <typename Sort_T>
std::ostream& operator<<(std::ostream& os, const sort_data<Sort_T>& rhs) {
    os << "[ ";
    for (auto v : (rhs.data))
        os << v << " ";
    os << "]\n";
    os << "Recursion calls : " << rhs.recursions << " Swaps: " << rhs.swaps << std::endl;
    return os;
}
template <typename T>
void sort_data<T>::pivot_median(long long low, long long high) {
    std::array<T, 3> arr{data.at(low), data.at(high), data.at((high + low) >> 1)};
    std::sort(arr.begin(), arr.end());
    auto loc = std::find(data.begin(), data.end(), arr.at(1));
    std::swap(data.at(low), *loc);
}
template <typename T>
long long sort_data<T>::partition(long long low, long long high) {
    auto pivot{data.at(low)};
    auto i{low - 1}, j{high + 1};
    while (true) {
        do {
            ++i;
        } while (data.at(i) < pivot);
        do {
            --j;
        } while (data.at(j) > pivot);
        if (i >= j)
            return j;
        ++swaps;
        std::swap(data.at(i), data.at(j));
    }
}

template <typename T>
void sort_data<T>::quicksort(long long low, long long high) {
    if (low < high) {
        auto p{partition(low, high)};
        ++recursions;
        quicksort(low, p);
        ++recursions;
        quicksort(p + 1, high);
    }
}

template <typename T>
void sort_data<T>::random_pivot(long long low, long long high) {
    auto r{random(low + 1, high)};
    std::swap(data.at(low), data.at(r));
}

template <typename T>
int64_t sort_data<T>::quicksort() {
    int64_t total_time{};
    if (0 < (data.size() - 1)) {
        pivot_median(0, data.size() - 1);
        total_time = calculate_time(0, data.size()-1);
    }
    return total_time;
}

template <typename T>
int64_t sort_data<T>::random_quicksort() {
    int64_t total_time{};
    if (0 < (data.size() - 1)) {
        random_pivot(0, data.size() - 1);
        total_time = calculate_time(0, data.size()-1);
    }
    return total_time;
}

template <>
void sort_data<int>::fill_random(size_t amount) {
    const long long low_range{0}, high_range{1000};
    for (auto i{0}; i < amount; ++i)
        data.push_back(random(low_range, high_range));
}
template <>
void sort_data<double>::fill_random(size_t amount) {
    const double low_range{0.0}, high_range{1000.0};
    for (auto i{0}; i < amount; ++i)
        data.push_back(random(low_range, high_range));
}
template <typename T>
void sort_data<T>::clear() {
    data.clear();
}

template <typename T>
void sort_data<T>::reset_counters() {
    swaps = 0;
    recursions = 0;
}

template <typename T>
void sort_data<T>::clear_all() {
    clear();
    reset_counters();
}

template <typename T>
int64_t sort_data<T>::calculate_time(long long low, long long high) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    quicksort(low, high);
    auto stop = high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    return duration.count();
}

}  // namespace mei