#pragma once
#include <iostream>
#include <vector>

long top_down_merge_sort(std::vector<int>& A);
long top_down_split(std::vector<int>& B, size_t iBegin, size_t iEnd, std::vector<int>& A);
long top_down_merge(std::vector<int>& A, size_t iBegin, size_t iMiddle, size_t iEnd, std::vector<int>& B);
template <typename T>
void display(std::vector<T> vec) {
    std::cout << "[ ";
    for (auto v : vec)
        std::cout << v << " ";
    std::cout << "]";
}