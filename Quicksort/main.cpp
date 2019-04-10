#include "quicksort.hpp"

int main(void) {
    // sets up the seed, the generator, and the distribution for the random vector
    // fill
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<long long> distribution(0, 100);
    /* Please use the following distribution if working with doubles, if with
    another type, well... std::uniform_real_distribution<> distribution(0.0,
    100.0);*/

    std::vector<int> vec{};
    const int vector_size{10};
    for (auto i{0}; i < vector_size; ++i) {
        vec.push_back(distribution(generator));
    }
    // just to print the vector before and after the quicksort, uncomment if the
    // vector is smaller
    /*for (const auto& v : vec)
      std::cout << v << " ";
    std::cout << std::endl;*/
    size_t total_time{};
    for (auto i{0}; i < 1000; ++i) {
        auto time = calculate_time(vec, quicksort);
        total_time += time;
        vec.clear();
        for (auto i{0}; i < vector_size; ++i) {
            vec.push_back(distribution(generator));
        }
    }
    /*for (const auto& v : vec)
      std::cout << v << " ";
    std::cout << std::endl;*/
    std::cout << "quicksort took " << total_time / 1000 << " microseconds as a mean" << std::endl;
    vec.clear();
    for (auto i{0}; i < vector_size; ++i) {
        vec.push_back(distribution(generator));
    }
    total_time = 0;
    for (auto i{0}; i < 1000; ++i) {
        auto time = calculate_time(vec, shellsort_ciura_basic);
        total_time += time;
        vec.clear();
        for (auto i{0}; i < vector_size; ++i) {
            vec.push_back(distribution(generator));
        }
    }
    std::cout << "shellsort took " << total_time / 1000 << " microseconds as a mean" << std::endl;
    // simple code to test std::sort and compare efficiency
    // can't use the same function since it works with iterators
    /*{
      auto start = std::chrono::high_resolution_clock::now();
      std::sort(vec.begin(), vec.end());
      auto stop = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); std::cout << "std::sort took " << duration.count() << "
      microseconds\n";
    }*/

    std::cout << "get it, hit it, kill it\n";
    return 0;
}