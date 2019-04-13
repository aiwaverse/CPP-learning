#include "quicksort.hpp"

int main(void) {
    // sets up the seed, the generator, and the distribution for the random vector

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<long long> distribution(0, 100);
    std::vector<int> vec1{}, vec2{};

    std::ifstream input_file;
    input_file.open("entrada.txt");
    int number_of_cases{};
    if (not input_file) {
        std::cerr << "error opening the file\n";
        return 1;
    }
    input_file >> number_of_cases;
    std::ofstream saida_mediana, saida_random{}, saida_ordenado{};
    saida_ordenado.open("vetores-ordenados.txt");
    saida_mediana.open("stats-primeiro.txt");
    saida_random.open("stats-aleatorio.txt");
    for (int i{0}; i < number_of_cases; ++i) {
        int number{}, number_of_elements{};
        input_file >> number_of_elements;
        for (auto j{0}; j < number_of_elements; ++j) {
            input_file >> number;
            vec1.push_back(number);
        }
        vec2 = vec1;
        auto time = calculate_time(vec1, quicksort);
        for(auto v:vec1)
          saida_ordenado << v << " ";
        saida_ordenado << std::endl;
        vec1.clear();
        saida_mediana << swaps << " " << recursives << " " << time << " nanoseconds" << std::endl;
        swaps = 0;
        recursives = 0;
        time = calculate_time(vec2, random_quicksort);
        for(auto v:vec2)
          saida_ordenado << v << " ";
        saida_ordenado << std::endl;
        vec2.clear();
        saida_random << swaps << " " << recursives << " " << time << " nanoseconds" << std::endl;
        swaps = 0;
        recursives = 0;

    }

    /* Please use the following distribution if working with doubles, if with
    another type, well... 
    std::uniform_real_distribution<> distribution(0.0,100.0);*/
    input_file.close();
    saida_mediana.close();
    saida_random.close();
    saida_ordenado.close();
    std::cout << "get it, hit it, kill it\n";
    return 0;
}