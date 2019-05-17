#include "hash.hpp"

std::ostream& operator<<(std::ostream& os, const Hash_Table& rhs) {
    os << "[ ";
    std::size_t i{0}, j{0};
    while (i < rhs.filled_nodes) {
        if (rhs.hash_table.at(j).occupied != false) {
            os << rhs.hash_table.at(j).word << " ";
            ++i;
            ++j;
        } else
            ++j;
    }
    os << "]" << std::endl;
    os << "Size: " << rhs.hash_table.size() << std::endl;
    return os;
}

Hash_Table::Hash_Table() : hash_table{} {
    const int initial_size{10};
    hash_table.resize(initial_size);  //starting hash_size
}
//adress calculator linear
std::size_t Hash_Table::linear_probing(std::size_t elmt) {
    return elmt % hash_table.size();
}
//others to be implemented

//this doubles the hash table size
void Hash_Table::resize(void) {
    std::vector<Hash_Node> vec_hash{};
    for (auto h : hash_table) {
        if (h.occupied == true) {
            vec_hash.push_back(h);
        }
    }
    auto sz = hash_table.size();
    hash_table.clear();
    filled_nodes = 0;
    hash_table.resize(sz * 2);
    std::cout << "after resize\n";
    for (auto v : vec_hash) {
        std::cout << "v.key: " << v.key << std::endl;
        insert(v.word);
    }
}
bool Hash_Table::insert(std::string word) {
    //lambda for easy change on the probing
    auto hash = [&](std::size_t e) { return this->linear_probing(e); };  // change this in case of changing the mapping or probing
    using std::size_t;
    long long e{-1}, mark{-1};
    size_t calc_adress{linear_probing(string_mapping_one(word))};  // change this in case of changing the mapping or probing
    size_t free_adress{calc_adress};
    do {
        if (hash_table.at(free_adress).used)
            if (hash_table.at(free_adress).occupied)
                if (hash_table.at(free_adress).word == word)
                    return false;
                else {
                    free_adress = hash(free_adress) + 1;
                }
            else {
                if (mark == -1)
                    mark = free_adress;
                free_adress = hash(free_adress);
            }
        else {
            if (mark == -1)
                mark = free_adress;
            break;
        }
    } while ((calc_adress != free_adress) and (e == -1));
    if ((e == -1) and (mark != -1)) {
        ++filled_nodes;
        hash_table.at(mark).key = string_mapping_one(word);
        hash_table.at(mark).used = true;
        hash_table.at(mark).occupied = true;
        hash_table.at(mark).word = word;
    }
    if (filled_nodes > (hash_table.size() / 2))
        resize();
    return true;
}
std::pair<int, long> Hash_Table::find(std::string word) {
    using std::size_t;
    long collisions{0};
    auto hash = [&](int e) { return this->linear_probing(e); };    //lambda for easy change on the probing
    int e{-1};
    size_t calc_adr{linear_probing(string_mapping_one(word))};  // change this in case of changing the mapping or probing
    size_t free_adr{calc_adr};
    do {
        if (hash_table.at(free_adr).used)
            if ((hash_table.at(free_adr).occupied) and (hash_table.at(free_adr).word == word))
                e = free_adr;
            else {
                free_adr = hash(free_adr) + 1;
                ++collisions;
            }
        else
            break;
    } while ((free_adr != calc_adr) and (e == -1));
    if(e==-1)
        collisions=-1;
    return std::make_pair(e, collisions);
}
bool Hash_Table::remove(std::string word) {
    using std::size_t;
    auto pos = find(word);
    if (pos.first != -1) {
        hash_table.at(pos.first).occupied = false;
        --filled_nodes;
        return true;
    } else
        return false;
}

void menu() {
    using std::cout;
    using std::endl;
    using std::left;
    using std::right;
    using std::setw;
    cout << setw(1) << left << "1" << setw(25) << right << " - Insert an element\n";
    cout << setw(1) << left << "2" << setw(25) << right << " - Find an element\n";
    cout << setw(1) << left << "3" << setw(25) << right << " - Remove an element\n";
    cout << setw(1) << left << "4" << setw(25) << right << " - Print the table\n";
    cout << setw(1) << left << "5" << setw(25) << right << " - Quit\n";
    cout << "Enter your option: ";
}
void parse_option(Hash_Table& hasht, const int op) {
    using std::cin;
    using std::cout;
    using std::endl;
    std::string elm{};
    switch (op) {
        case 1:
            cout << "Please enter the element to be inserted: ";
            cin >> elm;
            if (hasht.insert(elm))
                cout << "element sucefully inserted\n";
            else
                cout << "ERROR! element already exists\n";
            break;
        case 2: {
            cout << "Please enter the element to be found: ";
            cin >> elm;
            auto veri = hasht.find(elm);
            if (veri.first != -1)
                cout << "element found at table[" << veri.first << "] with " << veri.second << " collisions\n";
            else
                cout << "ERROR! element not found\n";
            break;
        }
        case 3:
            cout << "Please enter the element to be deleted: ";
            cin >> elm;
            if (hasht.remove(elm))
                cout << "Element deleted\n";
            else
                cout << "ERROR! Element not found\n";
            break;
        case 4:
            cout << hasht << endl;
            break;
        case 5:
            cout << "Quitting...\n";
            break;
        default:
            cout << "Please enter a valid option\n";
    }
}

//string mapping functions
long long Hash_Table::string_mapping_one(std::string word) {
    std::size_t hash{0};
    int p{4};
    p = pow(p, word.size());
    for (std::size_t i{0}; i < word.length(); ++i)
        hash = (p * hash + word.at(i)) % hash_table.size();
    return hash;
}

long long Hash_Table::string_mapping_two(std::string word) {
    std::size_t hash{0};
    const int p{9};
    for (std::size_t i{0}; i < word.length(); ++i)
        hash = (p * hash + word.at(i)) % hash_table.size();
    return hash;
}