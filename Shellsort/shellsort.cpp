//Made by aiwa in 24/03/2019, based on wikipedia's pseudocode
#include "shellsort.hpp"

void print_vector(std::vector<int> &vec)
{
    std::cout << "[ ";
    for (auto v : vec)
        std::cout << v << " ";
    std::cout << "]\n";
}

void shellsort_basic(std::vector<int> &vec)
{
    size_t maximum_power{vec.size() / 2};
    for (size_t gap{maximum_power}; gap >= 1; gap /= 2)
    {
        for (auto i{gap}; i < vec.size(); ++i) //cicyles the vector, starting at gap
        {
            auto j{i};
            while (j >= gap and vec.at(j - gap) > vec.at(i)) //while to find the correct position for insertion
                j -= gap;
            vec.insert(vec.begin() + (j), vec.at(i));
            vec.erase(vec.begin() + (i + 1));
        }
        std::cout << "after increments of size " << gap << " the list is: ";
        print_vector(vec);
    }
}

void shellsort_ciura(std::vector<int> &vec)
{
    std::vector<int> gap_list{1750, 701, 301, 132, 57, 23, 10, 4, 1}; //ciura's optimal list
    while (vec.size() >= gap_list.at(0))
    {
        int element = floor(gap_list.at(0) * 2.25);
        gap_list.insert(gap_list.begin(), element);
    }
    for (auto gap : gap_list) //for range loop could be changed for a normal for loop, but it's C++ so whatever
    {
        for (auto i{gap}; i < vec.size(); ++i) //cicyles the vector, starting at gap
        {
            auto j{i};
            while (j >= gap and vec.at(j - gap) > vec.at(i)) //while to find the correct position for insertion
                j -= gap;
            vec.insert(vec.begin() + (j), vec.at(i));
            vec.erase(vec.begin() + (i + 1));
        }
    }
}
void fill_vector_with_random(std::vector<int> &vec, size_t size)
{
    for (size_t i{0}; i < size; ++i)
        vec.push_back(rand());
}

void shellsort_even_more_basic(std::vector<int> &vec)
{
    size_t maximum_power{vec.size() / 2};
    for (size_t gap{maximum_power}; gap >= 1; gap /= 2)
    {
        for (auto i{gap}; i < vec.size(); ++i) //cicyles the vector, starting at gap
        {
            int j{};
            int temp = vec.at(i);
            for (j = i; j >= gap and vec[j - gap] > temp; j -= gap)
            {
                vec.at(j) = vec.at(j - gap);
            }
            vec.at(j) = temp;
        }
        std::cout << "after increments of size " << gap << " the list is: ";
        print_vector(vec);
    }
}

void shellsort_ciura_basic(std::vector<int> &vec)
{
    std::vector<int> gap_list{1750, 701, 301, 132, 57, 23, 10, 4, 1}; //ciura's optimal list
    while (vec.size() >= gap_list.at(0))
    {
        int element = floor(gap_list.at(0) * 2.25);
        gap_list.insert(gap_list.begin(), element);
    }
    for (auto gap : gap_list)
    {
        for (auto i{gap}; i < vec.size(); ++i) //cicyles the vector, starting at gap
        {
            int j{};
            int temp = vec.at(i);
            for (j = i; j >= gap and vec[j - gap] > temp; j -= gap)
            {
                vec.at(j) = vec.at(j - gap);
            }
            vec.at(j) = temp;
        }
    }
}
size_t calculate_time(std::vector<int> &vec, void (*sort)(std::vector<int> &)) //using a function pointer HOORAY
{
    auto start = std::chrono::high_resolution_clock::now();
    sort(vec); //cute
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); //but it just calculates run time
    return duration.count();
}