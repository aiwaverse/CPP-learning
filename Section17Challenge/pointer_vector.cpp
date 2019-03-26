#include "pointer_vector.hpp"

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make()
{
    auto pointer_to_vector_of_pointers = std::make_unique<std::vector<std::shared_ptr<Test>>>();
    return pointer_to_vector_of_pointers;
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num)
{
    for(auto i{0};i<num;++i)
    {
        std::cout << "Please enter the number for the data point [" << i << "]:\n";
        int data_to_push {};
        std::cin >> data_to_push;
        auto shared_to_push = std::make_shared<Test>(data_to_push);
        vec.push_back(shared_to_push);
    }
}
void display(const std::vector<std::shared_ptr<Test>>&vec)
{
    std::cout << "[ ";
    for(auto v:vec)
    {
        std::cout << v->get_data() << " ";   //deference the pointer to a test object and display the data
    }
    std::cout << "]\n";
}