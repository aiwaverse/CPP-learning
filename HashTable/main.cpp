#include "hash.hpp"

int main(void) {
    using std::cin;
    using std::cout;
    using std::endl;
    Hash_Table table{};
    int option{};
    do {
        menu();
        cin >> option;
        if (option != 5)
            parse_option(table, option);

    } while (option != 5);

    cout << "trying to be stronger for you" << endl;
    return 0;
}