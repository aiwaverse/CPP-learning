#include "radix.hpp"

int main(void) {
    std::vector<int> numbers{1234, 777, 0, 91};
    display(numbers);
    radix(numbers);
    display(numbers);
    std::cout << "end" << std::endl;
    return 0;
}