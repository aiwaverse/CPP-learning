#pragma once
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
namespace open {
class Hash_N {
   private:
    std::string _content{};
    size_t _key{0};
    bool _occupied{false};
    bool _used{false};
    long _collisions{0};

   public:
    // constructors
    Hash_N(std::string s) : _content{s} {};
    Hash_N() = default;
    Hash_N(const Hash_N&) = default;
    Hash_N(Hash_N&&) = default;
    //functions to return the elements
    size_t key(void) { return _key; };
    long collisions(void) { return _collisions; };
    bool occupied(void) { return _occupied; };
    bool used(void) { return _used; };
    std::string string(void) { return _content; };
    void set_key(long k) { _key = k; };
    void set_occupied(bool b) { _occupied = b; };
    void set_used(bool b) { _used = b; };
    void set_string(std::string& s) { _content = s; };
    void set_collisions(long n) { _collisions = n; };
};
class Hash_Table {
   private:
    std::vector<Hash_N> table{};
    const unsigned mapping{};
    unsigned number_of_strings{0};
    //mapping of strings to size_t and probings
    size_t mapping_one(const std::string&);
    size_t mapping_two(const std::string&);
    size_t mapping_chooser(const std::string&);
    size_t linear_probing(size_t, const unsigned);
    size_t double_probing(size_t, const unsigned);  //double probing and not double hashing to keep a pattern

   public:
    unsigned long long total_collisions{0};
    Hash_Table(const unsigned n, const std::string& s, const unsigned i = 1) : table(n, {s}), mapping{i} {
        if (mapping != 1 and mapping != 2)
            throw std::runtime_error("ERROR, THE MAPPING IS NOT 1 OR 2\n");
    };  //initialize table with n elements with s
    Hash_Table(const unsigned n, const unsigned i = 1) : table(n, {""}), mapping{i} {
        if (mapping != 1 and mapping != 2)
            throw std::runtime_error("ERROR, THE MAPPING IS NOT 1 OR 2\n");
    };  //initialize table with n elements with empty string
    Hash_Table(const Hash_Table&) = default;
    Hash_Table(Hash_Table&&) = default;
    bool insert(std::string);
    long long find(std::string);
    void print(std::ofstream& os);
    void print(void);
};

}  //namespace open