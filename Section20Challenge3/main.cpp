#include "set.hpp"

int main(void) {
    std::ifstream word_file{};
    std::map<std::string, unsigned> text_map{};
    std::cout << "Please enter 1 or 2" << std::endl;
    int option{};
    do {
        std::cin >> option;
    } while (option != 1 and option != 2);
    if (option == 1) {
        word_file.open("words.txt");
        if (word_file) {
            while (not word_file.eof()) {
                std::string word{};
                word_file >> word;
                clean_string(word);
                make_lower_case(word);
                put_on_map(word, text_map);
            }
            display_part_1(text_map);
            word_file.close();
        } else {
            std::cerr << "error opening the file for part one" << std::endl;
            return 1;
        }
    } else {
        word_file.open("words.txt");
        std::map<std::string, std::set<unsigned>> text_with_lines_map{};
        size_t line_count{1};
        if (word_file) {
            while (not word_file.eof()) {
                std::string input{};
                std::getline(word_file, input);
                clean_string(input);
                std::stringstream iss{input};
                std::string word{};
                while (iss >> word) {
                    make_lower_case(word);
                    put_on_map_2(word, line_count, text_with_lines_map);
                }
                ++line_count;
            }
            display_part_2(text_with_lines_map);
            word_file.close();
        } else {
            std::cerr << "error opening the file for part two" << std::endl;
            return 2;
        }
    }

    std::cout << "ba banana ba banananana" << std::endl;
    return 0;
}