#include "count.hpp"

void counting_sort(std::vector<int>& array) {
    int min{*std::min_element(array.begin(), array.end())};
    int max{*std::max_element(array.begin(), array.end())};
    int range{max - min + 1};
    std::vector<int> count(range), output(array.size());
    for (size_t i{0}; i < array.size(); ++i)
        ++count.at(array.at(i) - min);
    for (size_t i{1}; i < count.size(); ++i)
        count.at(i) += count.at(i - 1);
    for (long long i{static_cast<long long>(array.size()) - 1}; i >= 0; --i){
        output.at(count.at(array.at(i)-min)-1) = array.at(i);
        --count.at(array.at(i)-min);
    }
    output.swap(array);

}