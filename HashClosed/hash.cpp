#include "hash.hpp"

namespace closed {
std::size_t Hash_Table::insert(std::string s) {
    std::size_t pos{};
    if(mapping == 1)
        pos = string_mapping_one(s);
    else if(mapping ==2)
        pos = string_mapping_two(s);
    table.at(pos).content_list.insert(s);

}
//string mapping functions
std::size_t Hash_Table::string_mapping_one(std::string word) {
    return std::hash<std::string>{}(word) % table.size();
}

std::size_t Hash_Table::string_mapping_two(std::string word) {
    std::size_t hash{0};
    const int p{9};
    for (int i{0}; i < word.length(); ++i)
        hash = (p * hash + word.at(i)) % table.size();
    return hash;
}
}  // namespace closed