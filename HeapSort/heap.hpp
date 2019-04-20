#pragma once
#include <iostream>
#include <vector>

void heapify(std::vector<int>& vec, int size, int i);
void heapsort(std::vector<int>& vec, int size);
void heapsort(std::vector<int>& vec);
template <typename T>
void display(std::vector<T> vec){
	std::cout << "[ ";
	for(auto v:vec)
		std::cout << v << " ";
	std::cout << "]\n";
}
