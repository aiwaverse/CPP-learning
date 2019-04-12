#include <iostream>
#include <vector>

long long _mergeSort(std::vector<int>& arr, std::vector<int>& temp, int left, int right);
long long merge(std::vector<int>& arr, std::vector<int>& temp, int left, int mid, int right);

long long mergeSort(std::vector<int>& arr, long long array_size) {
  std::vector<int> temp{arr};
  return _mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function that sorts the input array and  
returns the number of inversions in the array. */
long long _mergeSort(std::vector<int>& arr, std::vector<int>& temp, int left, int right) {
  int mid;
  long long inv_count = 0;
  if (right > left) {
    /* Divide the array into two parts and  
        call _mergeSortAndCountInv()  
        for each of the parts */
    mid = (right + left) / 2;

    /* Inversion count will be sum of  
        inversions in left-part, right-part  
        and number of inversions in merging */
    inv_count = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid + 1, right);

    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid + 1, right);
  }
  return inv_count;
}

/* This funt merges two sorted arrays  
and returns inversion count in the arrays.*/
long long merge(std::vector<int>& arr, std::vector<int>& temp, int left, int mid, int right) {
  int i, j, k;
  long long inv_count = 0;

  i = left; /* i is index for left subarray*/
  j = mid;  /* j is index for right subarray*/
  k = left; /* k is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right)) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];

      /* this is tricky -- see above  
            explanation/diagram for merge()*/
      inv_count = inv_count + (mid - i);
    }
  }

  /* Copy the remaining elements of left subarray  
(if there are any) to temp*/
  while (i <= mid - 1)
    temp[k++] = arr[i++];

  /* Copy the remaining elements of right subarray  
(if there are any) to temp*/
  while (j <= right)
    temp[k++] = arr[j++];

  /*Copy back the merged elements to original array*/
  for (i = left; i <= right; i++)
    arr[i] = temp[i];

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