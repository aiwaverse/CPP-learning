#include "heap.hpp"

void heapify(std::vector<int>& vec, int size, int i) {
    int largest{i};
    int left{2 * i + 1};
    int right{2 * i + 2};
    if ((left < size) and (vec.at(left) > vec.at(largest)))
        largest = left;
    if ((right < size) and (vec.at(right) > vec.at(largest)))
        largest = right;
    if (largest != i) {
        std::swap(vec.at(i), vec.at(largest));
        heapify(vec, size, largest);
    }
}
void heapsort(std::vector<int>& vec, int size) {
    for (int i{size / 2 - 1}; i >= 0; --i)
        heapify(vec, size, i);
    for (int i{size - 1}; i >= 0; --i) {
        std::swap(vec.at(0), vec.at(i));
        heapify(vec, i, 0);
    }
}
void heapsort(std::vector<int>& vec){
	heapsort(vec, vec.size());
}