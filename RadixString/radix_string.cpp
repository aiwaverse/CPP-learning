#include "radix_string.hpp"
using std::string;
using std::vector;

void clean_string(std::string& word) {
    string new_word{};
    for (size_t i{0}; i < word.size(); ++i) {
        if (isalpha(word.at(i)))
            new_word += tolower(word.at(i));
    }
    word.swap(new_word);
}

size_t getMax(const vector<string>& arr) {
    auto max = *std::max_element(arr.begin(), arr.end(),
                                 [&](string const& lhs, string const& rhs) {
                                     return lhs.size() < rhs.size();
                                 });
    return max.size();
}

void count_sort(vector<string>& a, size_t k) {
    vector<string> b(a.size());
    std::array<int, 257> c{};
    //no need to initialize c
    for (size_t i{0}; i < a.size(); ++i) {
        if (k < a.at(i).size()) {
            ++c.at(a.at(i).at(k) + 1);
        } else {
            ++c.at(0);
        }
    }
    for (size_t i{1}; i < c.size(); ++i)
        c.at(i) += c.at(i - 1);
    for (long long i{static_cast<long long>(a.size() - 1)}; i >= 0; --i) {
        b.at(c.at(k < a.at(i).size() ? a.at(i).at(k) + 1 : 0) - 1) = a.at(i);
        --c.at(k < a.at(i).size() ? a.at(i).at(k) + 1 : 0);
    }
    a.swap(b);
}

void radixSort(vector<string>& b) {
    size_t max{getMax(b)};
    for (long long digit{static_cast<long long>(max)}; digit > 0; --digit) {
        count_sort(b, digit - 1);
    }
}

void fill_vector_from_file(std::vector<std::string>& string_vector, std::ifstream& file) {
    while (!file.eof()) {
        std::string word{};
        file >> word;
        string_vector.push_back(word);
    }
}
void count_word(const std::vector<std::string>& words, std::ofstream& file) {
    auto it = words.begin();
    while (it != words.end()) {
        auto count = std::count(words.begin(), words.end(), *it);
        file << *it << " : " << count << std::endl;
        it += count;
    }
}
void count_word_fast(const std::vector<std::string>& words, std::ofstream& file) {
    int j{0};
    for (int i{0}; i < words.size()-1; ++i) {
        if (words.at(i) == words.at(i + 1)) {
            ++j;
        } else {
            file << words.at(i) << " : " << j+1 << std::endl;
            j=0;
        }
    }
}