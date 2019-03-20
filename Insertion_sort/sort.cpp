#include "sort.hpp"

long long int insertion_sort(std::vector<int>& vec){
    long long int count_of_operations{0};    
    for(int i{1};i<vec.size();++i) //cycles the whole vector, starting at index 1 
    {
        int j{i-1};
        while(j>=0 && vec.at(i)<vec.at(j) )     //decrements j while j is inside range (>=0) and while vec[j] is bigger than vec[i]
        {
            j--;
        }
        if(j<i-1){      //just to make sure we don't make changes on an element that "never moved"
        vec.insert(vec.begin()+j+1,vec.at(i));      //this inserts the vec[i] element at the corrent position, then deletes the original
        vec.erase(vec.begin()+i+1);s
        count_of_operations++;
        }
    }
    return count_of_operations;
};
