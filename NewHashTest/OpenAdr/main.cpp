#include <limits>
#include "openadr.hpp"

int main(void) {
    using std::string;
    open::Hash_Table tbl(15000, 1U);
    std::cout << std::boolalpha;
    std::ifstream archive{"nomes_10000.txt"};
    std::ofstream output{"saida.txt"};
    if ((not archive) or (not output)) {
        throw std::runtime_error("Error opening files!\n");
    }
    string word;
    while (std::getline(archive, word)) {
        tbl.insert(word);
    }
    tbl.print(output);
    archive.close();
    output.close();
    std::cout << "dalla dalla" << std::endl;

    return 0;
}
