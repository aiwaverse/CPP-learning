#include "openadr.hpp"
namespace open {
size_t Hash_Table::mapping_one(const std::string& s) {
    size_t hash{37};
    size_t i{0};
    constexpr unsigned prime_a{54059};
    constexpr unsigned prime_b{86969};
    while (i < s.size()) {
        hash = (hash * prime_a) ^ (s.at(i) * prime_b);
        ++i;
    }
    return hash;
}
size_t Hash_Table::mapping_two(const std::string& s) {
    size_t i{0};
    uint32_t hash{0};
    while (i != s.size()) {
        hash += s.at(i++);
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash;
}
size_t Hash_Table::mapping_chooser(const std::string& s) {
    switch (mapping) {
        case 1:
            return mapping_one(s);
            break;
        case 2:
            return mapping_two(s);
            break;
        default:  //will never happen but the compiler gives me a warning if i don't do this
            return 0;
    }
}
//probing functions
size_t Hash_Table::double_probing(size_t c, const unsigned i) {
    return c + i * (29 - (c % 7));
}
size_t Hash_Table::linear_probing(size_t c, const unsigned i) {
    return c + i;
}

bool Hash_Table::insert(std::string s) {
    size_t i{0};
    auto probing = [&](size_t c, unsigned i) mutable -> size_t { return this->double_probing(c, i); };  //lambda for easy replacement
    size_t key{mapping_chooser(s)};
    auto o_key{key};
    size_t pos{key % table.size()};
    auto fpos{pos};
    while (true) {
        if (table.at(pos).occupied() == false)  //if the space is availabe
            break;
        //remove first condition
        if (table.at(pos).key() == static_cast<size_t>(key))  //if the key at the position is the same, the element is the same
            return false;
        ++i;
        key = probing(o_key, i);  //o_key is to use the original key in the function and not the new key
        pos = key % table.size();
        if (pos == fpos)
            return false;
    }
    table.at(pos).set_key(key);
    table.at(pos).set_occupied(true);
    table.at(pos).set_string(s);
    table.at(pos).set_used(true);
    table.at(pos).set_collisions(i);
    total_collisions += i;
    ++number_of_strings;
    return true;
}

long long Hash_Table::find(std::string s) {
    size_t i{0};

    auto probing = [&](size_t c, unsigned i) mutable -> size_t { return this->double_probing(c, i); };  //lambda for easy replacement
    size_t key{mapping_chooser(s)};
    auto o_key{key};
    size_t pos{key % table.size()};
    while (table.at(pos).used() == true) {
        if (table.at(pos).key() == key)  //if the space is availabe
            return i + 1;
        ++i;
        key = probing(o_key, i);
        pos = key % table.size();
    }
    return -1;
}

void Hash_Table::print(std::ofstream& os) {
    for (auto e : table) {
        if (e.key() != 0)
            os << "Key: " << e.key() << ", Word: " << e.string() << ", collisions to insert: " << e.collisions() << std::endl;
    }
    os << "Number of filled nodes: " << number_of_strings << ", " << (static_cast<double>(number_of_strings) / table.size()) * 100 << "\% of the table is occupied" << std::endl;
    os << "Number of collisions on construction: " << total_collisions << ", with a mean of: " << static_cast<double>(total_collisions) / number_of_strings << std::endl;
    std::cout << "Number of filled nodes: " << number_of_strings << ", " << (static_cast<double>(number_of_strings) / table.size()) * 100 << "\% of the table is occupied" << std::endl;
    std::cout << "Number of collisions on construction: " << total_collisions << ", with a mean of: " << static_cast<double>(total_collisions) / number_of_strings << std::endl;

}
void Hash_Table::print(void) {
    for (auto e : table) {
        if (e.key() != 0)
            std::cout << "Key: " << e.key() << ", Word: " << e.string() << ", collisions to insert: " << e.collisions() << std::endl;
    }
    std::cout << "Number of filled nodes: " << number_of_strings << ", " << (number_of_strings / table.size()) * 100 << "%% of the table is occupied" << std::endl;
    std::cout << "Number of collisions on construction: " << total_collisions << ", with a mean of: " << static_cast<double>(total_collisions) / number_of_strings << std::endl;
}
}  // namespace open