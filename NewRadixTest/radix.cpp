#include "radix.hpp"

void display(const std::vector<int>& disp) {
    for (auto v : disp)
        std::cout << v << " ";
    std::cout << std::endl;
}

unsigned get_number_of_digits(unsigned i) {
    return i > 0 ? (int)log10((double)i) + 1 : 1;
}

void radix(std::vector<int>& vec) {
    auto element = abs(*std::max_element(vec.begin(), vec.end()));
    element = get_number_of_digits(element);
    element = pow(10, element - 1);
    for (int expo{1}; expo <= element; expo *= 10) {
        _radix(vec, expo);
    }
}

void _radix(std::vector<int>& vec, unsigned expo) {
    std::vector<std::queue<int, std::list<int>>> queue_radix(10);
    for (size_t i{0}; i < vec.size(); ++i) {
        queue_radix.at(((vec.at(i)) / expo) % 10).push(vec.at(i));
    }
    for (size_t i{0}, j{0}; i < queue_radix.size(); ++i) {
        if (queue_radix.at(i).empty()) {
            continue;
        }
        vec.at(j) = queue_radix.at(i).front();
        queue_radix.at(i).pop();
        if (!queue_radix.at(i).empty())
            --i;
        ++j;
    }
}

void fill_random(std::vector<int>& vec) {
    vec.clear();
    using namespace std::chrono;
    auto time_clock = high_resolution_clock::now();
    auto seed = time_clock.time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, 10000);
    for (auto i{0}; i < 1000; ++i) {
        vec.push_back(distribution(generator));
    }
}
int64_t test_radix_new_time(std::vector<int>& vec) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    radix(vec);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    return duration.count();
}

int64_t test_radix_old_time(std::vector<int>& vec) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    radix_sort(vec);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    return duration.count();
}

void string_radix_msd(std::vector<std::string>& words) {
    for (auto i{0}; i < words.size(); ++i){

    }
}

void _string_radix_msd(std::vector<std::string>& words, int index){
    
}