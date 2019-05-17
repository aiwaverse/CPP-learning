#include "openadr.hpp"

int main(void){
    open::Hash_Table tbl(10, 2);
    std::cout << std::boolalpha;
    std::cout << tbl.insert("Mei") << std::endl;
    std::cout << tbl.insert("Agatha") << std::endl;
    std::cout << tbl.insert("Agatha") << std::endl;
    tbl.print();

    return 0;
}

