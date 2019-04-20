#pragma once
#include <iostream>
#include <vector>

void top_down_merge_sort(std::vector<int>& A);
void top_down_split(std::vector<int>& B, size_t iBegin, size_t iEnd, std::vector<int>& A);
void top_down_merge(std::vector<int>& A, size_t iBegin, size_t iMiddle, size_t iEnd, std::vector<int>& B);
void bottom_up_merge_sort(std::vector<int>& A, std::vector<int>& B);
void bottom_up_merge_sort(std::vector<int>& A);
void bottom_up_merge(std::vector<int>& A, size_t iLeft, size_t iRight, size_t iEnd, std::vector<int>& B);
template <typename T>
void display(std::vector<T> vec) {
    std::cout << "[ ";
    for (auto v : vec)
        std::cout << v << " ";
    std::cout << "]";
}
template <typename T>
T min(T a, T b) {
    return (a < b ? a : b);
}