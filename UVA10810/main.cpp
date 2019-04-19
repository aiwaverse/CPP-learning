#include <iostream>
#include <vector>

long long _mergeSort(std::vector<int>& arr, std::vector<int>& temp, int left, int right);
long long merge(std::vector<int>& arr, std::vector<int>& temp, int left, int mid, int right);

long long mergeSort(std::vector<int>& arr, long long array_size) {
    std::vector<int> temp{arr};
    return _mergeSort(arr, temp, 0, array_size - 1);
}
long long _mergeSort(std::vector<int>& arr, std::vector<int>& temp, int left, int right) {
    int mid;
    long long inv_count{};
    if (right > left) {
        mid = (right + left) / 2;
        inv_count = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
long long merge(std::vector<int>& arr, std::vector<int>& temp, int left, int mid, int right) {
    int i{left}, j{mid}, k{right};
    long long inv_count{};
    while ((i <= mid - 1) && (j <= right)) {
        if (arr.at(i) <= arr.at(j)) {
            temp.at(k) = arr.at(i);
            ++k;
            ++i;
        } else {
            temp.at(k) = arr.at(j);
            ++k;
            ++j;
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left subarray  
(if there are any) to temp*/
    while (i <= mid - 1) {
        temp.at(k) = arr.at(i);
        ++k; ++i;
    }

    /* Copy the remaining elements of right subarray  
(if there are any) to temp*/
    while (j <= right) {
        temp.at(k) = arr.at(j);
        ++k;
        ++j;
    }

    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr.at(i) = temp.at(i);

    return inv_count;
}

int main(void) {
    long number{};
    while ((std::cin >> number) and (number != 0)) {
        std::vector<int> sequences{};
        for (int i{0}; i < number; ++i) {
            int n;
            std::cin >> n;
            sequences.push_back(n);
        }
        auto counter{mergeSort(sequences, sequences.size())};
        std::cout << counter << std::endl;
    }
    return 0;
}