#include "radix_string.hpp"

int main(void) {
    std::ifstream frankestein_input{}, war_and_peace_input{};
    frankestein_input.open("frankestein.txt");
    war_and_peace_input.open("war_and_peace.txt");
    // check input files
    if ((not frankestein_input) or (not war_and_peace_input)) {
        std::cerr << "Error opening input files" << std::endl;
        return 1;
    }
    std::ofstream frankestein_ordenado{}, war_and_peace_ordenado{};
    frankestein_ordenado.open("frankestein_ordenado.txt");
    war_and_peace_ordenado.open("war_and_peace_ordenado.txt");
    //check ordered files
    if ((not frankestein_ordenado) or (not war_and_peace_ordenado)) {
        std::cerr << "Error opening output ordered files" << std::endl;
        return 2;
    }
    std::vector<std::string> word_string{};
    //fill the word_string vector with all the words on the file
    fill_vector_from_file(word_string, frankestein_input);
    frankestein_input.close();
    std::cout << "ordering first file..." << std::endl;
    //call msd radix for the string
    radixSort(word_string);
    for (size_t i{0}; i < word_string.size(); ++i){
        frankestein_ordenado << word_string.at(i) << std::endl;
    }
    frankestein_ordenado.close();
    std::ofstream frankestein_contagem{};
    frankestein_contagem.open("frankestein_contagem.txt");
    if(not frankestein_contagem){
        std::cerr << "error opening first counting file" << std::endl;
        return 3;
    }
    std::cout << "counting words on first file..." << std::endl;
    count_word_fast(word_string, frankestein_contagem);
    frankestein_contagem.close();
    word_string.clear();
    fill_vector_from_file(word_string, war_and_peace_input);
    war_and_peace_input.close();
    std::cout << "ordering second file..." << std::endl;
    radixSort(word_string);
    for (size_t i{0}; i < word_string.size(); ++i){
        war_and_peace_ordenado << word_string.at(i) << std::endl;
    }
    war_and_peace_ordenado.close();
    std::ofstream war_and_peace_contagem{};
    war_and_peace_contagem.open("war_and_peace_contagem.txt");
    if(not war_and_peace_contagem){
        std::cerr << "error opening second counting file" << std::endl;
        return 4;
    }
    std::cout << "counting words on second file..." << std::endl;
    count_word_fast(word_string, war_and_peace_contagem);
    war_and_peace_contagem.close();
    std::cout << "oh my mistake" << std::endl;
    return 0;
}