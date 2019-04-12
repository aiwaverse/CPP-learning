#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

long long inversions(std::vector<int>& v) {
  std::set<int> base{};
  //std::copy(v.begin(), v.end(), std::inserter(base, base.end()));
  base.insert(v.at(0));
  std::set<int>::iterator set_it{};
  long long invcount{0};
  for (unsigned i{1}; i < v.size(); ++i) {
    base.insert(v.at(i));
    set_it = base.upper_bound(v.at(i));
    invcount += std::distance(set_it, base.end());
  }
  return invcount;
}

int main(void) {
  std::vector<int> sequences{};
  int number{};
  while ((std::cin >> number) and (number != 0)) {
    std::vector<int> sequences{};

    for (int i{0}; i < number; ++i) {
      int n;
      std::cin >> n;
      sequences.push_back(n);
    }
    auto counter{inversions(sequences)};
    std::cout << counter << std::endl;
  }
  return 0;
}