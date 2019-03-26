#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <memory>

void fill_vector_with_random(std::vector<int>& vec, size_t size);
void shellsort_ciura_basic(std::vector<int> &vec);
void print_vector(std::vector<int>& vec);
void shellsort_ciura(std::vector<int>& vec);
void shellsort_basic(std::vector<int>& vec);
void shellsort_even_more_basic(std::vector<int>& vec);
size_t calculate_time(std::vector<int>&vec, void(*sort)(std::vector<int>&));