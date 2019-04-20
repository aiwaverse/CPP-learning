#include "merge.hpp"

int main(void) {
    std::vector<int> vec{1, 3, 5, 2, 4, 6};
    display(vec);
    std::vector<int> vec_cpy {vec};
    std::cout << std::endl;
    top_down_merge_sort(vec);
    std::cout << "After top down merge sort: ";
    display(vec);
    std::cout << std::endl;
    std::cout << "After bottom up merge sort: ";
    bottom_up_merge_sort(vec_cpy);
    display(vec_cpy);
    std::cout << std::endl;
    std::cout << "mei is the cutest" << std::endl;
    return 0;
}