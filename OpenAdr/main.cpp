#include <limits>
#include <map>
#include <sstream>
#include "openadr.hpp"

int main(int argc, char *argv[]) {
    using std::string;
    //i could have used do/while to not allow different input, but i'm mean
    std::stringstream iss{};
    if (argc == 3) {
        std::string args{};
        args += argv[1];
        args += " ";
        args += argv[2];
        iss.str(args);
    }
    else if(argc != 1){
        throw std::runtime_error("Not enough arguments or too many arguments");
    }
    unsigned map{};
    unsigned prob{};
    while ((not(iss >> map)) or (not(iss >> prob))) {
        iss.str(std::string{});  //clear the stream after bad input
        iss.clear();             //seems to work just with this, but
        std::cout << "Enter the mapping and the probing( 1 or 2 for both, use any other number and the program will stop ):\n";
        std::string s{};
        std::getline(std::cin, s);
        iss.str(s);
    }
    unsigned sz{};
    if (prob == 2)
        sz = 13339;
    else
        sz = 13334;
    open::Hash_Table tbl(sz, map, prob);
    std::cout << std::boolalpha;
    std::ifstream archive{"nomes_10000.txt"};
    std::ifstream consultas{"consultas.txt"};
    std::ofstream output_1{"saida_construcao.txt"};
    std::ofstream output_2{"saida_consulta_encontrados.txt"};
    std::ofstream output_3{"saida_consulta_nao_encontrados.txt"};
    if ((not archive) or (not output_1) or (not output_2) or (not output_3) or (not consultas)) {
        throw std::runtime_error("Error opening one or more files!\n");
    }
    string word;
    while (std::getline(archive, word)) {
        tbl.insert(word);
    }
    tbl.print(output_1);
    output_1.close();
    archive.close();
    std::multimap<long long, std::string> ordering{};  //this is a multimap just to sort the search, hope it's ok to use
    long long total_checkings{0};
    int found_words{0};
    int not_found_words{0};
    while (std::getline(consultas, word)) {
        auto checks{tbl.find(word)};
        if (checks != -1) {
            output_2 << word << ": ";
            output_2 << "Number of comparasions: " << checks << std::endl;
            ordering.insert(std::make_pair(checks, word));
            ++found_words;
        } else {
            output_3 << word << ": !!!!!Name not found!!!!!" << std::endl;
            ++not_found_words;
        }
        total_checkings += checks;
    }
    std::cout << "Number of found words: " << found_words << std::endl;
    std::cout << "Number of not found words: " << not_found_words << std::endl;
    std::cout << "Smallest number of comparasions: " << ordering.begin()->first << std::endl
              << "Words with that number of comparasions: " << std::endl;
    for (auto o : ordering) {
        if (o.first == ordering.begin()->first)
            std::cout << o.second << std::endl;
    }
    std::cout << "Largest number of comparasions: " << ordering.rbegin()->first << std::endl
              << "Words with that number of comparasions: " << std::endl;
    for (auto o : ordering) {
        if (o.first == ordering.rbegin()->first)
            std::cout << o.second << std::endl;
    }
    std::cout << "Mean of comparasions: " << static_cast<double>(total_checkings) / (found_words + not_found_words) << std::endl;
    consultas.close();
    output_2.close();
    output_3.close();

    return 0;
}
