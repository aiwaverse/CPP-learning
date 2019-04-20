#include "merge.hpp"

void top_down_merge_sort(std::vector<int>& A) {
    std::vector<int> B{A};
    top_down_split(B, 0, B.size(), A);
}

void top_down_split(std::vector<int>& B, size_t iBegin, size_t iEnd, std::vector<int>& A) {
    if (iEnd - iBegin < 2)
        return;
    auto iMiddle{(iBegin + iEnd) / 2};
    top_down_split(A, iBegin, iMiddle, B);
    top_down_split(A, iMiddle, iEnd, B);
    top_down_merge(B, iBegin, iMiddle, iEnd, A);
}
void top_down_merge(std::vector<int>& A, size_t iBegin, size_t iMiddle, size_t iEnd, std::vector<int>& B) {
    auto i{iBegin}, j{iMiddle};
    for (auto k{iBegin}; k < iEnd; ++k) {
        if ((i < iMiddle) and ((j >= iEnd) or (A.at(i) <= A.at(j)))) {
            B.at(k) = A.at(i);
            ++i;
        } else {
            B.at(k) = A.at(j);
            ++j;
        }
    }
}
void bottom_up_merge_sort(std::vector<int>& A){
    std::vector<int> temp{A};
    bottom_up_merge_sort(A, temp);
}
void bottom_up_merge_sort(std::vector<int>& A, std::vector<int>& B) {
    for (size_t width{1}; width < A.size(); width *= 2) {
        for (size_t i{0}; i < A.size(); i += 2 * width) {
            bottom_up_merge(A, i, min(i + width, A.size()), min(i + 2 * width, A.size()), B);
            A = B;
        }
    }
}
void bottom_up_merge(std::vector<int>& A, size_t iLeft, size_t iRight, size_t iEnd, std::vector<int>& B) {
    auto i{iLeft}, j{iRight};
    for (auto k{iLeft}; k < iEnd; ++k) {
        if ((i < iRight) and ((j >= iEnd) or ((i < A.size() and j < A.size()) and A.at(i) <= A.at(j)))) {
            B.at(k) = A.at(i);
            ++i;
        }
        else{
            B.at(k) = A.at(j);
            ++j;
        }
    }
}