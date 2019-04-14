#include "ind_functions.hpp"

long long random(long long low_range, long long high_range){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distribution(low_range, high_range);
    return distribution(rng); 
}
double random(double low_range, double high_range){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<> distribution(low_range, high_range);
    return distribution(rng); 
}