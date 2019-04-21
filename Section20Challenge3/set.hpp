#pragma once
#include <iostream>
#include <set>
#include <list>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cctype>
#include <map>
#include <string>
#include <vector>

void clean_string(std::string& word);
void make_lower_case(std::string& word);
void display_part_1(const std::map<std::string, unsigned>& my_map);
void display_part_2(const std::map<std::string, std::set<unsigned>>& my_map);
void put_on_map(const std::string& word, std::map<std::string, unsigned>& my_map);
void put_on_map_2(const std::string& word, unsigned counter, std::map<std::string, std::set<unsigned>>& my_map);
