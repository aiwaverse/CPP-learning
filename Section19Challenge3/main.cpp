#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

void convert_to_lower_case(std::string &word)       //accepting any case, we convert to lower case
{
    for (auto &character : word)
        character = tolower(character);
}
int main(void)
{
    std::ifstream play_file;
    play_file.open("romeoandjuliet.txt");
    if (not play_file)
    {
        std::cerr << "error opening file\n";
        return 1;
    }
    std::cout << "Please enter the word you want to search: " << std::endl;
    std::string word_to_search{};
    std::cin >> word_to_search;
    convert_to_lower_case(word_to_search);
    std::string word{};
    long unsigned int count_of_word{}, total_of_words{};
    while (play_file >> word)
    {
        total_of_words++;
        convert_to_lower_case(word);
        if (word.find(word_to_search) not_eq std::string::npos)
        {
            count_of_word++;
        }
    }
    std::cout << "On a total of " << total_of_words << " words, ";
    std::cout << word_to_search << " was found " << count_of_word << " times\n";
    play_file.close();
    std::cout << "CLEAR! *bomb explodes*" << std::endl;
    return 0;
}