#include "quicksort.hpp"

int main(void) {
  // sets up the seed, the generator, and the distribution for the random vector
  auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  std::uniform_int_distribution<long long> distribution(0, 100);
  /* Please use the following distribution if working with doubles, if with
    another type, well... 
    std::uniform_real_distribution<> distribution(0.0,100.0);*/

  std::vector<int> vec{};
  const int vector_size{100}, number_of_iterations{100};
  for (auto i{0}; i < vector_size; ++i) {
    vec.push_back(distribution(generator));
  }
  // just to print the vector before and after the quicksort, uncomment if the vector is smaller
  /*for (const auto& v : vec)
      std::cout << v << " ";
    std::cout << std::endl;*/
  size_t total_time{};
  for (auto i{0}; i < number_of_iterations; ++i) {
    auto time = calculate_time(vec, quicksort);
    total_time += time;
    vec.clear();
    for (auto j{0}; j < vector_size; ++j) {
      vec.push_back(distribution(generator));
    }
  }
  /*for (const auto& v : vec)
      std::cout << v << " ";
    std::cout << std::endl;*/
  std::cout << "quicksort took " << total_time / number_of_iterations << " microseconds as a mean" << std::endl;
  total_time = 0;
  //now we do random_quicksort
  for (auto i{0}; i < number_of_iterations; ++i) {
    auto time = calculate_time(vec, random_quicksort);
    total_time += time;
    vec.clear();
    for (auto j{0}; j < vector_size; ++j) {
      vec.push_back(distribution(generator));
    }
  }
  std::cout << "random quicksort took " << total_time / number_of_iterations << " microseconds as a mean" << std::endl;
  for (auto i{0}; i < number_of_iterations; ++i) {
    vec.clear();
    for (auto j{0}; j < vector_size; ++j) {
      vec.push_back(distribution(generator));
    }
    auto time = calculate_time(vec, shellsort_ciura_basic);
    total_time += time;
  }
  std::cout << "shellsort took " << total_time / number_of_iterations << " microseconds as a mean" << std::endl;
  // simple code to test std::sort and compare efficiency
  // can't use the same function since std::sort works with iterators
  total_time = 0;
  {
    for (auto i{0}; i < number_of_iterations; ++i) {
      vec.clear();
      for (auto j{0}; j < vector_size; ++j)
        vec.push_back(distribution(generator));
      auto start = std::chrono::high_resolution_clock::now();
      std::sort(vec.begin(), vec.end());
      auto stop = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
      total_time += duration.count();
    }
  }
  std::cout << "std::sort took " << total_time / number_of_iterations << " microseconds as a mean\n";

  std::cout << "get it, hit it, kill it\n";
  return 0;
}