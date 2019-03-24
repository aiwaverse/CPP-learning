#include "shellsort.hpp"

void shellsort(std::vector<int>& vec)
{
    int gap_list[]{1750, 701, 301, 132, 57, 23, 10, 4, 1}; //based on ciura's optimal list
    for (auto gap : gap_list)                              //for range loop could be changed for a normal for loop, but it's C++ so whatever
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
    std::cout << std::endl;
}