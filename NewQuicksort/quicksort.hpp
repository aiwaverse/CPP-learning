<<<<<<< HEAD
#include <algorithm>
#include <array>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
=======
#include <fstream>
#include <iostream>
#include <random>
#include <chrono>
>>>>>>> 4bdb666e8b4bde04126d2f1652c42649bc9ee00f
#include <string>
#include <vector>

namespace mei {
template <typename Sort_T>
class sort_data {
<<<<<<< HEAD
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

   public:
    sort_data() : data{}, recursions{}, swaps{} {};
    void fill_random();
    void push_back(Sort_T n) {
        data.push_back(n);
    }
    void quicksort(long long low, long long high);
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
    std::array<long long, 3> arr{data.at(low), data.at(high), data.at((high + low) >> 1)};
    std::sort(arr.begin(), arr.end());
    auto loc = std::find(data.begin(), data.end(), arr.at(1));
    std::swap(data.at(low), *loc);
}
template <typename T>
long long sort_data<T>::partition(long long low, long long high) {
    pivot_median(low, high);
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
        std::swap(data.at(i), data.at(j));
    }
}

template <typename T>
void sort_data<T>::quicksort(long long low, long long high) {
    if (low < high) {
        auto p{partition(low, high)};
        quicksort(low, p);
        quicksort(p + 1, high);
    }
}
=======
    friend std::ostream& operator<<(std::ostream &os, sort_data<Sort_T>& rhs);
 private:
  std::vector<Sort_T> data{};
  long long recursions{};
  long long swaps{};
  long long partition_median();
  long long random_partition();

 public:
  sort_data() : data{}, recursions{}, swaps{}{};
  void fill_random();
  void push_back(Sort_T n) {
    data.push_back(n);
  }
  void quicksort(long long low, long long high);
};
std::ostream& operator<<(std::ostream &os, sort_data<Sort_T>& rhs)
{
    os << "[ ";
    for(auto v:rhs.data)
        os << v << " ";
    os << "]\n";
    os << "Recursion calls : " << rhs.recursions << "Swaps: " << rhs.swaps << std::endl;
    return os;
}
>>>>>>> 4bdb666e8b4bde04126d2f1652c42649bc9ee00f
}  // namespace mei