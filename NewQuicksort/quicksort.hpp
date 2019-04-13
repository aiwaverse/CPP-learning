#include <fstream>
#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <vector>

namespace mei {
template <typename Sort_T>
class sort_data {
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
}  // namespace mei