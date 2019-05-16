#include "hash.hpp"

namespace closed {
Hash_Table::Hash_Table() {
  int op{};
  do {
    std::cout << "1 for the first string mapping, 2 for the second:\n";
    std::cin >> op;
  } while (op != 1 and op != 2);
  mapping = op;
  const unsigned short size{10};
  table.resize(size);
}
std::size_t Hash_Table::insert(std::string s) {
  std::size_t pos{};
  if (mapping == 1)
    pos = string_mapping_one(s);
  else if (mapping == 2)
    pos = string_mapping_two(s);
  table.at(pos).content_list.push_back(s);
}
bool Hash_Table::remove(std::string s) {
  std::size_t pos{};
  if (mapping == 1)
    pos = string_mapping_one(s);
  else if (mapping == 2)
    pos = string_mapping_two(s);
  for (int i{0}; i < table.at(pos).content_list.size(); ++i) {
    if (table.at(pos).content_list.at(pos) == s) {
      table.at(pos).content_list.erase(table.at(pos).content_list.begin() + pos);
      return true;
    }
  }
  return false;
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

long Hash_Table::find(std::string s){
  std::size_t pos{};
  if (mapping == 1)
    pos = string_mapping_one(s);
  else if (mapping == 2)
    pos = string_mapping_two(s);
  for (int i{0}; i < table.at(pos).content_list.size(); ++i) {
    if (table.at(pos).content_list.at(pos) == s) {
      return ++i;
    }
  }
    return -1;
}

}  // namespace closed