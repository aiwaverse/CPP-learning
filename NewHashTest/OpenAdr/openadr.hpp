#pragma once
#include <iostream>
#include <string>
#include <vector>
namespace open {
class Hash_N {
   private:
    std::string _content{};
    long _key{-1};
    bool _occupied{false};
    bool _used{false};

   public:
    // constructors
    Hash_N(std::string s) : _content{s} {};
    Hash_N() = default;
    Hash_N(const Hash_N&) = default;
    Hash_N(Hash_N&&) = default;
    //functions to return the elements
    long key(void) { return _key; };
    bool occupied(void) { return _occupied; };
    bool used(void) { return _used; };
    std::string string(void) { return _content; };
};
class Hash_Table {
   private:
    std::vector<Hash_N> table{};
    //mapping of strings to size_t and probings
    size_t mapping_one(const std::string&);
    size_t mapping_two(const std::string&);
    long linear_probing(const std::string&);
    long double_probing(const std::string&);  //double probing and not double hashing to keep a pattern
   public:
    Hash_Table(unsigned n) : table(n, {""}){};  //initialize table with n elements with empty string
    Hash_Table(const Hash_Table&) = default;
    Hash_Table(Hash_Table&&) = default;
};

}  //namespace open