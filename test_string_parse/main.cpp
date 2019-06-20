#include <iostream>
#include <string>

int main(void) {
    std::string parsing{"112809,\"Diebuster \"\"Top wo Narae 2\"\" (2004)\",\"Action|Animation|Drama|Sci-Fi\""};
    unsigned i{1};
    std::string new_one{};
    std::cout << parsing << "\n";
    auto init = parsing.find(",\"");
    i = init+2;
    while (((parsing[i - 1] != ',') or (parsing[i] != '\"')) and (i < parsing.size())) {
        new_one.push_back(parsing[i-1]);
        ++i;
    }
    std::cout << new_one << "\n";
    return 0;
}