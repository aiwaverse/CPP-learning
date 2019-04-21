#include "set.hpp"

void clean_string(std::string& word) {
    std::string result{};
    for (auto letter : word) {
        if (isalnum(letter) or isblank(letter))
            result += letter;
    }
    word.swap(result);
}

void make_lower_case(std::string& word) {
    for (auto& letter : word) {
        letter = tolower(letter);
    }
}

void display_part_1(const std::map<std::string, unsigned>& my_map) {
    std::cout << std::setw(12) << std::left << "Word" << std::setw(7) << std::right << "Count" << std::endl;
    std::cout << "===================\n";
    for (const auto& pair : my_map) {
        std::cout << std::setw(12) << std::left << pair.first << std::setw(7) << std::right << pair.second << std::endl;
    }
}

void display_part_2(const std::map<std::string, std::set<unsigned>>& my_map) {
    for (const auto& element : my_map) {
        std::cout << "[" << element.first << ": [ ";
        for (const auto& set_element : element.second) {
            std::cout << std::setw(2) << std::right << set_element << " ";
        }
        std::cout << "]]" << std::endl;
    }
}

void put_on_map(const std::string& word, std::map<std::string, unsigned>& my_map) {
    if (my_map.find(word) != my_map.end()) {
        ++my_map.at(word);
    } else {
        my_map[word] = 1;
    }
}

void put_on_map_2(const std::string& word, unsigned counter, std::map<std::string, std::set<unsigned>>& my_map) {
    my_map[word].insert(counter);
}