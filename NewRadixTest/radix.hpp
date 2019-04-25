#pragma once
#include <iostream>
#pragma once
#include "radix_classic.hpp"
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <array>
#include <chrono>
#include <random>
#include <cmath>

unsigned get_number_of_digits(unsigned i);
void radix(std::vector<int>& vec);
void _radix(std::vector<int>& to_sort, unsigned expo);
void fill_random(std::vector<int> &vec);
int64_t test_radix_new_time(std::vector<int>& vec);
int64_t test_radix_old_time(std::vector<int>& vec);