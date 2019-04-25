#include "radix.hpp"

int main(void) {
    std::vector<std::string> letters{"ab", "abc", "abcd", "a", "batata"};
    display(letters);
    sort_string(letters, 0, letters.size()-1, 0);
    display(letters);
    std::cout << "love myself today" << std::endl;
    return 0;
}