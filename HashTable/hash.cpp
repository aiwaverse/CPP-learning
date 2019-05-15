#include "hash.hpp"
std::ostream& operator<<(std::ostream& os, const Hash_Table& rhs) {
    os << "[ ";
    std::size_t i{0}, j{0};
    while (i < rhs.filled_nodes) {
        if (rhs.hash_table.at(j).key != -1) {
            os << rhs.hash_table.at(j).key << " ";
            ++i;
            ++j;
        } else
            ++j;
    }
    os << "]";
    os << std::endl
       << "Size: " << rhs.hash_table.size() << std::endl;
    return os;
}

Hash_Table::Hash_Table() : hash_table{} {
    hash_table.resize(10);  //starting hash_size
}
//adress calculator linear
std::size_t Hash_Table::linear_probing(int elmt) {
    return elmt % hash_table.size();
}
//others to be implemented

//this doubles the hash table size
void Hash_Table::resize(void) {
    hash_table.resize(hash_table.size() * 2);
}
bool Hash_Table::insert(int elmnt) {
    using std::size_t;
    long long e{-1}, mark{-1};
    size_t calc_adress{linear_probing(elmnt)};
    size_t free_adress{calc_adress};
    do {
        if (hash_table.at(free_adress).used)
            if (hash_table.at(free_adress).occupied)
                if (hash_table.at(free_adress) == elmnt)
                    return false;
                else
                    free_adress = linear_probing(free_adress) + 1;
            else {
                if (mark == -1)
                    mark = free_adress;
                free_adress = linear_probing(free_adress);
            }
        else {
            if (mark == -1)
                mark = free_adress;
            break;
        }
    } while ((calc_adress != free_adress) and (e == -1));
    if ((e == -1) and (mark != -1)) {
        ++filled_nodes;
        hash_table.at(mark).key = elmnt;
        hash_table.at(mark).used = true;
        hash_table.at(mark).occupied = true;
    }
    if (filled_nodes > (hash_table.size() / 2))
        resize();
    return true;
}