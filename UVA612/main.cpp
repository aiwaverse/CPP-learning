//Aceito pela UVA
//"Your submission with number 23099676 for the problem 612 - DNA Sorting has received the verdict Accepted."


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Dna
{
    friend bool operator<(const Dna &lhs, const Dna &rhs);
    friend bool operator>(const Dna &lhs, const Dna &rhs);
    friend bool operator==(const Dna &lhs, const Dna &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Dna &rhs);

  public:
    std::string dna_sequence{};
    int inversions{0};
    Dna() = default;
    Dna(std::string sequence) : dna_sequence{sequence} {}
};
std::ostream &operator<<(std::ostream &os, const Dna &rhs)
{
    os << rhs.dna_sequence;
    return os;
}
bool operator<(const Dna &lhs, const Dna &rhs)
{
    return (lhs.inversions < rhs.inversions) ? true : false;
}
bool operator>(const Dna &lhs, const Dna &rhs)
{
    return not(lhs < rhs);
}
bool operator==(const Dna &lhs, const Dna &rhs)
{
    return (lhs.inversions == rhs.inversions) ? true : false;
}

void measure_inversions(Dna &sequence_to_be_ordered)
{
    for (auto i{0}; i < sequence_to_be_ordered.dna_sequence.size(); ++i)
        for (auto j{i + 1}; j < sequence_to_be_ordered.dna_sequence.size(); ++j)
            if (sequence_to_be_ordered.dna_sequence.at(i) > sequence_to_be_ordered.dna_sequence.at(j))
            {
                sequence_to_be_ordered.inversions++;
            }
}

int main(void)
{
    int M{};
    std::cin >> M;
    char c = getchar();
    std::vector<Dna> dna_vector{};
    for (auto i{0}; i < M; ++i)
    {
        int n{}, m{};
        std::cin >> n >> m;
        for (auto j{0}; j < m; j++)
        {
            Dna dna_to_read{};
            std::string sequence{};
            std::cin >> sequence;
            dna_to_read.dna_sequence = sequence;
            dna_vector.push_back(dna_to_read);
        }
        for (auto &dnas : dna_vector)
            measure_inversions(dnas);
        std::stable_sort(dna_vector.begin(), dna_vector.end());
        for (auto dnas : dna_vector)
            std::cout << dnas << std::endl;
        dna_vector.clear();
        if(i!=(M-1))
            std::cout << std::endl;
    }
    return 0;
}