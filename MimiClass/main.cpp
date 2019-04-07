#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::string;

class aiwa_heart{
    private:
    void mimi(unsigned long long int amount_of_love_to_give);
    public:
    void love(unsigned long long int love);
};

void aiwa_heart::mimi(unsigned long long int amount_of_love_to_give)
{
    cout << "aiwa sent mimi " << amount_of_love_to_give << " love" << endl;
}
void aiwa_heart::love(unsigned long long int love)
{
    mimi(love);
}

int main(void)
{
    aiwa_heart heart{};
    heart.love(18446744073709551615U);
    cout << "This program has ended sucefully" << endl;
    return 0;
}