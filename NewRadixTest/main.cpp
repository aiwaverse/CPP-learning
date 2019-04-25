#include "radix.hpp"

int main(void) {
    std::vector<int> numbers{ 12312, 812, 192, 0, 21, 123, 4812};
    display(numbers);
    radix(numbers);
    display(numbers);
    std::cout << "love myself today" << std::endl;
    return 0;
}