#pragma once
#include <iostream>
#include "radix_classic.hpp"
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <chrono>
#include <random>
#include <cmath>

unsigned get_number_of_digits(unsigned i);
void radix(std::vector<int>& vec);
void _radix(std::vector<int>& to_sort, unsigned expo);
void display(const std::vector<int>& disp);
void fill_random(std::vector<int> &vec);
int64_t test_radix_new_time(std::vector<int>& vec);
int64_t test_radix_old_time(std::vector<int>& vec);
void radix_sort_msd(std::vector<int>& vec);
void _string_radix_msd(std::vector<std::string>& words, int index);
void string_radix_msd(std::vector<std::string>& words);