#pragma once
#include <iomanip>
#include <iostream>
#include <memory>
#include <functional>
#include <string>
#include <ostream>
#include <vector>

struct Hash_Node {
    int key{-1};
    bool used{false};
    bool occupied{false};
    bool operator==(const Hash_Node& rhs) {
        return this->word == rhs.word;
    }
    bool operator==(const std::string& rhs) {
        return this->word == word;
    }
    std::string word {};
};
//if more is to be implemented, maybe print the actual content

class Hash_Table {
    friend std::ostream& operator<<(std::ostream& os, const Hash_Table& rhs);

   private:
    std::vector<Hash_Node> hash_table{};
    unsigned filled_nodes{0};
    //adress calculators;
    std::size_t linear_probing(std::size_t);
    std::size_t quadratic_probing(std::size_t);
    std::size_t double_hashing(std::size_t);

   public:
    Hash_Table();
    Hash_Table(const Hash_Table&) = default;
    Hash_Table(Hash_Table&&) = default;
    Hash_Table& operator=(Hash_Table rhs);
    void resize(void);
    bool insert(std::string);
    long find(std::string);
    bool remove(std::string);
    std::size_t string_mapping_one(std::string word);
    std::size_t string_mapping_two(std::string word);
};

void menu(void);
void parse_option(Hash_Table&, const int);
