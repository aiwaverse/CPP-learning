#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

void counting_sort(std::vector<int>& array);
template <typename T>
void display(std::vector<T> vec){
	std::cout << "[ ";
	for(auto v:vec)
		std::cout << v << " ";
	std::cout << "]\n";
}