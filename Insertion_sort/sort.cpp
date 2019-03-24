/* Made by aiwa, on 19/03/2019, insertion sort based on class 
Changed to the binary search version on 23/03/2019 */
#include "sort.hpp"

long long int insertion_sort(std::vector<int> &vec)
{
    long long int count_of_operations{0};
    for (int i{1}; i < vec.size(); ++i) //cycles the whole vector, starting at index 1
    {
        int j{i - 1};
        int location = binary_search_for_insertion(vec, vec.at(i), 0, j);
        vec.insert(vec.begin() + location, vec.at(i)); //this inserts the vec[i] element at the corrent position, then deletes the original
        vec.erase(vec.begin() + i + 1);
        count_of_operations++;
    }
    return count_of_operations;
};
int binary_search(std::vector<int> &vec, const int target)
{
    size_t top{vec.size() - 1}, bottom{0};
    while (bottom <= top)
    {
        int mean = floor((top + bottom) / 2);
        if (vec.at(mean) < target)
        {
            bottom = mean + 1;
        }
        else if (vec.at(mean) > target)
        {
            if (mean - 1 >= 0) //when this happens, the element wasn't found, so we return -1
                top = mean - 1;
            else
                return -1; //we can't decrease top because it's a size_t variable
        }
        else
            return mean;
    }
    return -1;
}
int binary_search_for_insertion(const std::vector<int> &vec, int node, int left, int right)
{
    if (right <= left) //if we only have one element left to comapre;
        return ((node > vec.at(left)) ? left + 1 : left);
    int mean{(left + right) / 2};
    //    if(vec.at(mean)==node)      //if the mean is the same value as the element we want to change
    //        return mean+1;
    if (node > vec.at(mean)) //if the node is larger than the element vec[mean], we call it again, but with mean+1 as left
        return binary_search_for_insertion(vec, node, mean + 1, right);
    else //if the node is smaller, we call it again, but not right will be mean-1
        return binary_search_for_insertion(vec, node, left, mean - 1);
}