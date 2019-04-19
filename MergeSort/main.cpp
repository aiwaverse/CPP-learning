#include "merge.hpp"

int main(void) {
    std::vector<int> vec{1, 3, 5, 2, 4, 6};
    display(vec);
    std::cout << std::endl;
    auto inv = top_down_merge_sort(vec);
    display(vec);
    std::cout << std::endl;
    std::cout << "Inversions: " << inv << std::endl;
    std::cout << "mei is the cutest" << std::endl;
    return 0;
}