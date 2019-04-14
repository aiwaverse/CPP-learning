#include "quicksort.hpp"

int main() {
    mei::sort_data<int> vec, vec2;
    std::ifstream input_file{};
    std::string name{};
    std::cout << "Please enter the file name: \n";
    std::cin >> name;
    input_file.open(name);
    if (not input_file) {
        std::cerr << "error opening the input file!\n";
        return 1;
    }
    std::ofstream stats_primeiro{}, stats_aleatorio{};
    stats_primeiro.open("stats_primeiro.txt");
    stats_aleatorio.open("stats_aleatorio.txt");
    if ((not stats_primeiro) or (not stats_aleatorio)) {
        std::cerr << "error opening the output files!\n";
        return 2;
    }
    long number_of_cases{};
    char print_vector{};
    do {
        std::cout << "Do you need the vector printed on the output files (y or n)?\n";
        std::cin >> print_vector;
    } while ((print_vector != 'y') and (print_vector != 'n'));
    std::cout << "Ordering..." << std::endl;
    input_file >> number_of_cases;
    for (int i{0}; i < number_of_cases; ++i) {
        long number_of_elements{};
        input_file >> number_of_elements;
        for (int j{0}; j < number_of_elements; ++j) {
            long number{};
            input_file >> number;
            vec.push_back(number);
        }
        vec2 = vec;
        auto time_passed = vec.quicksort();
        if(print_vector == 'y')
            stats_primeiro << vec;
        stats_primeiro << "Time passed: " << time_passed << " micrseconds" << std::endl;
        vec.clear_all();
        time_passed = vec2.random_quicksort();
        if(print_vector == 'y')
            stats_aleatorio << vec2;
        stats_aleatorio << "Time passed: " << time_passed << " micrseconds" << std::endl;
        vec2.clear_all();
    }
    input_file.close();
    stats_primeiro.close();
    stats_aleatorio.close();

    std::cout << "podo podohae (aka everything worked, check folder for output files)" << std::endl;
    return 0;
}