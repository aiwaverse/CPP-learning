#include "hash.hpp"

std::ostream& operator<<(std::ostream& os, const Hash_Table& rhs) {
    os << "[ ";
    std::size_t i{0}, j{0};
    while (i < rhs.filled_nodes) {
        if (rhs.hash_table.at(j).occupied != false) {
            os << rhs.hash_table.at(j).key << " ";
            ++i;
            ++j;
        } else
            ++j;
    }
    os << "]";
    return os;
}

Hash_Table::Hash_Table() : hash_table{} {
    const int initial_size{10};
    hash_table.resize(initial_size);  //starting hash_size
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
    //lambda for easy change on the probing
    auto hash = [&](int e){return this->linear_probing(e);};
    using std::size_t;
    long long e{-1}, mark{-1};
    size_t calc_adress{hash(elmnt)};
    size_t free_adress{calc_adress};
    do {
        if (hash_table.at(free_adress).used)
            if (hash_table.at(free_adress).occupied)
                if (hash_table.at(free_adress) == elmnt)
                    return false;
                else
                    free_adress = hash(free_adress) + 1;
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
        hash_table.at(mark).key = elmnt;
        hash_table.at(mark).used = true;
        hash_table.at(mark).occupied = true;
    }
    if (filled_nodes > (hash_table.size() / 2))
        resize();
    return true;
}
int Hash_Table::find(int c) {
    using std::size_t;
    //lambda for easy change on the probing
    auto hash = [&](int e){return this->linear_probing(e);};
    int e{-1};
    size_t calc_adr{hash(c)};
    size_t free_adr{calc_adr};
    do {
        if (hash_table.at(free_adr).used)
            if ((hash_table.at(free_adr).occupied) and (hash_table.at(free_adr).key == c))
                e = free_adr;
            else
                free_adr = hash(free_adr) + 1;
        else
            break;
    } while ((free_adr != calc_adr) and (e == -1));
    return e;
}
bool Hash_Table::remove(int c) {
    using std::size_t;
    auto pos = find(c);
    if (pos != -1) {
        hash_table.at(pos).occupied = false;
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
    int elm{};
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
            if (veri != -1)
                cout << "element found at table[" << veri << "]\n";
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