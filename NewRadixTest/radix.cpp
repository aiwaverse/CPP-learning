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
    std::vector<std::queue<int, std::list<int>>> queue_radix(10);
    auto element = *std::max_element(vec.begin(), vec.end());
    element = get_number_of_digits(element);
    element = pow(10, element - 1);
    for (int expo{10}; expo <= element*10; expo *= 10) {
        int correct_digit{expo / 10};
        for (size_t i{0}; i < vec.size(); ++i) {
            queue_radix.at(((vec.at(i)) / correct_digit) % 10).push(vec.at(i));
        }
        for (size_t i{0}, j{0}; i < queue_radix.size(); ++i) {
            if (queue_radix.at(i).empty()) {
                continue;
            }
            vec.at(j) = queue_radix.at(i).front();
            queue_radix.at(i).pop();
            if(!queue_radix.at(i).empty())
                --i;
            ++j;
        }
    }
}