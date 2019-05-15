#pragma once
#include <iomanip>
#include <iostream>
#include <ostream>
#include <vector>

struct Hash_Node {
    int key{-1};
    bool used{false};
    bool occupied{false};
    bool operator==(const Hash_Node& rhs) {
        return this->key == rhs.key;
    }
    bool operator==(const int& rhs) {
        return this->key == rhs;
    }
};
//quick stream insertion operator overload, to print each Hash_Node, only with the key
//if more is to be implemented, maybe print the actual content

class Hash_Table {
    friend std::ostream& operator<<(std::ostream& os, const Hash_Table& rhs);

   private:
    std::vector<Hash_Node> hash_table{};
    unsigned filled_nodes{0};
    //adress calculators;
    std::size_t linear_probing(int elmt);
    std::size_t quadratic_probing(int elmt);
    std::size_t double_hashing(int elmt);
    void redistribute(void); //to be implemented?

   public:
    Hash_Table();
    Hash_Table(const Hash_Table&) = default;
    Hash_Table(Hash_Table&&) = default;
    Hash_Table& operator=(Hash_Table rhs);
    void resize(void);
    bool insert(int);
    int find(int);
    bool remove(int);
};

void menu(void);
void parse_option(Hash_Table&, const int);
