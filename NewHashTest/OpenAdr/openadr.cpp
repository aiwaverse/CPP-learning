#include "openadr.hpp"
namespace open {
size_t Hash_Table::mapping_one(const std::string& s) {
    std::size_t hash{s.size()};
    const int p = static_cast<int>(pow(2, hash));
    for (std::size_t i{0}; i < s.length(); ++i)
        hash = (p * hash + s.at(i));
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
size_t Hash_Table::double_probing(const std::string& s, const unsigned i) {
    size_t c{mapping_chooser(s)};
    return c + i * (c % 7);
}
size_t Hash_Table::linear_probing(const std::string& s) {
    return mapping_chooser(s);
}

bool Hash_Table::insert(std::string s) {
    size_t i{0};
    size_t key{};
    size_t pos{};
    for (; i < table.size(); ++i) {
        key = double_probing(s, i);
        pos = key % table.size();
        if (table.at(pos).occupied() == false)  //if the space is availabe
            break;
        if (table.at(pos).key() != -1 and table.at(pos).key() == static_cast<size_t>(key))  //if the key at the position is the same, the element is the same
            return false;
    }
    if (i != table.size()) {
        table.at(pos).set_key(key);
        table.at(pos).set_occupied(true);
        table.at(pos).set_string(s);
        table.at(pos).set_used(true);
        return true;
    } else  //full table?
        return false;
}
void Hash_Table::print(void) {
    for (auto e : table) {
        std::cout << "Key: " << e.key() << ", Word: " << e.string() << std::endl;
    }
}
}  // namespace open