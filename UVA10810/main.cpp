#include <iostream>
#include <vector>

long top_down_merge_sort(std::vector<int>& A);
long top_down_split(std::vector<int>& B, size_t iBegin, size_t iEnd, std::vector<int>& A);
long top_down_merge(std::vector<int>& A, size_t iBegin, size_t iMiddle, size_t iEnd, std::vector<int>& B);

long top_down_merge_sort(std::vector<int>& A) {
    std::vector<int> B{A};
    auto inv_count = top_down_split(B, 0, B.size(), A);
    return inv_count;
}

long top_down_split(std::vector<int>& B, size_t iBegin, size_t iEnd, std::vector<int>& A) {
    long inv_count{0};
    if (iEnd - iBegin < 2)
        return inv_count;
    auto iMiddle{(iBegin + iEnd) / 2};
    inv_count = top_down_split(A, iBegin, iMiddle, B);
    inv_count += top_down_split(A, iMiddle, iEnd, B);
    inv_count += top_down_merge(B, iBegin, iMiddle, iEnd, A);

    return inv_count;
}
long top_down_merge(std::vector<int>& A, size_t iBegin, size_t iMiddle, size_t iEnd, std::vector<int>& B) {
    auto i{iBegin}, j{iMiddle};
    long inversion_count{0};
    for (auto k{iBegin}; k < iEnd; ++k) {
        if ((i < iMiddle) and ((j >= iEnd) or (A.at(i) <= A.at(j)))) {
            B.at(k) = A.at(i);
            ++i;
        } else {
            B.at(k) = A.at(j);
            ++j;
            inversion_count = inversion_count + (iMiddle - i);
        }
    }
    return inversion_count;
}

int main(void) {
    std::vector<int> test_case{};
    int number{};
    do {
        std::cin >> number;
        if (number != 0) {
            for (size_t i{0}; i < number; ++i) {
                int n{};
                std::cin >> n;
                test_case.push_back(n);
            }
            auto inv = top_down_merge_sort(test_case);
            std::cout << inv << std::endl;
            test_case.clear();
        }
    } while (number != 0);
    return 0;
}