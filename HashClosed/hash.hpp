#pragma once
#include <iostream>
#include <string>
#include <vector>
namespace closed {
struct H_Node {
  std::vector<std::string> content_list{};
  unsigned long collisions{0};
};
class Hash_Table {
 private:
  std::vector<H_Node> table{};
  std::size_t string_mapping_one(std::string word);
  std::size_t string_mapping_two(std::string word);
  unsigned mapping{1};

 public:
  Hash_Table();
  std::size_t insert(std::string);
  bool remove(std::string);
  long find(std::string);
};

}  //namespace closed