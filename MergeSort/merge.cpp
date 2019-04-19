#include "merge.hpp"

long top_down_merge_sort(std::vector<int>& A) {
    std::vector<int> B{A};
    auto inv_count = top_down_split(B, 0, B.size(), A);
	return inv_count;
}

long top_down_split(std::vector<int>& B, size_t iBegin, size_t iEnd, std::vector<int>& A) {
	long inv_count{};
    if (iEnd - iBegin < 2)
        return 0;
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