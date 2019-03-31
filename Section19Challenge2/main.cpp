#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main(void)
{
    std::ifstream students_file;
    students_file.open("responses.txt");
    if (not students_file)
    {
        std::cerr << "Error opening file\n";
        return 1;
    }
    const int amount_of_answers{5}; //change this if you increase the amount of questions
    char correct_answers[amount_of_answers]{};
    for (auto &c : correct_answers)
        students_file >> c;   //fills the "correct_answers" array
    int class_total{};        //total number of correct answers by the class
    int amount_of_students{}; //number of students
    std::string name;
    std::cout << "Grade of Mamamoo on the test:\n";
    while (students_file >> name)
    {
        amount_of_students++;
        char answers[amount_of_answers]{};
        for (auto &c : answers)
            students_file >> c; //fills the answers array
        int amount_of_correct_answers{};
        for (int i{0}; i < amount_of_answers; ++i)
        {
            if (answers[i] == correct_answers[i])
            {
                amount_of_correct_answers++;
                class_total++;
            }
        }
        std::cout << std::setw(10) << std::left << name;
        std::cout << std::setw(10) << amount_of_correct_answers << std::endl;
    }
    double mean_score{static_cast<float>(class_total) / amount_of_students};
    std::cout << "Mean score: " << mean_score << std::endl;

    std::cout << "yep nothing exploded" << std::endl;
    return 0;
}