#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <cctype>
#include <sstream>
#include <fstream>
#include <vector>

void clean_string(std::string& word);
void radixSort(std::vector<std::string>& b);
void count_sort(std::vector<std::string>& a, size_t k);
void fill_vector_from_file(std::vector<std::string>& string_vector, std::ifstream& file);
size_t getMax(const std::vector<std::string>& arr);
void count_word(const std::vector<std::string>& words, std::ofstream& file);
void count_word_fast(const std::vector<std::string>& words, std::ofstream& file);