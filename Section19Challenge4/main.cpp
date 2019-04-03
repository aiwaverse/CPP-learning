#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

int main(void)
{
    std::ifstream play_input_file("romeoandjuliet.txt");
    std::ofstream play_output_file("file_with_numbers.txt", std::ios::trunc);
    if ((not play_input_file) or (not play_output_file))
    {
        std::cerr << "Error opening one of the files" << std::endl;
        return 1;
    }
    std::string word_line{}; //string to read from the txt file
    int line_number{0};
    while (getline(play_input_file, word_line))
    {
        if ((word_line.empty()) or (word_line == "\r"))  //damn you linux
            play_output_file << std::endl;
        else
        {
            line_number++;
            play_output_file << std::setw(7) << std::left << line_number << " " << word_line << std::endl;
        }
    }
    std::cout << "COPY COMPLETED\n";
    play_input_file.close();
    play_output_file.close();

    std::cout << "woop there it is" << std::endl;
    return 0;
}