#include "radix.hpp"

int main(void) {
    std::vector<int> numbers{3221, 1, 10, 9680, 577, 9420, 7, 5622, 4793, 2030, 3138, 82, 2599, 743, 4127};
    display(numbers);
    radix_sort_msd(numbers);
    display(numbers);
    std::cout << "love myself today" << std::endl;
    return 0;
}