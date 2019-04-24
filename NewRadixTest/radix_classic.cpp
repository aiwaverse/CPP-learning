#include "radix.hpp"

void counting_sort(std::vector<int>& array, int expo) {
    std::vector<int> output(array.size()), count(10);
    for (size_t i{0}; i < array.size(); ++i)
        ++count.at((array.at(i) / expo) % 10);
    for (size_t i{1}; i < count.size(); ++i)
        count.at(i) += count.at(i - 1);
    for (long long i{static_cast<long long>(array.size()) - 1}; i >= 0; --i) {
		output.at(count.at((array.at(i)/expo)%10)-1) =array.at(i);
		--count.at((array.at(i)/expo)%10);
	}
	output.swap(array);
}
void radix_sort(std::vector<int>& vec) {
    int max{*std::max_element(vec.begin(), vec.end())};
    for (int expo{1}; max / expo > 0; expo *= 10)
        counting_sort(vec, expo);
}