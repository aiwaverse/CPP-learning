//an even more different shellsort code, this time full of variants, with powers of 2 and the ciura list + extra numbers
//use calculate time to get execution time
//the shellsort_basic and shellsort_even_more_basic run on powers of 2, first one with insert/erase, second with the classic method
//same for shellsort_ciura and shellsort_ciura_basic
//the "classic" methods are extremely more efficient

#include "shellsort.hpp"
using namespace std::chrono;
int main(void)
{
  srand(time(nullptr));
  std::vector<int> vect_test{};
  fill_vector_with_random(vect_test, 10000);
  size_t time{};
  const int execution_times{1000};
  for (int i{0}; i < execution_times; ++i)
  {
    time += calculate_time(vect_test, shellsort_ciura_basic);
    vect_test.clear();
    fill_vector_with_random(vect_test,10000);
  }
  time/=execution_times;
  std::cout << "shellsort_ciura_basic took " << time << " microseconds as a mean" << std::endl;
  time=0;
  for (int i{0}; i < execution_times; ++i)
  {
    time += calculate_time(vect_test, shellsort_ciura);
    vect_test.clear();
    fill_vector_with_random(vect_test,10000);
  }
  time/=execution_times;
  std::cout << "shellsort_ciura took " << time << " microseconds as a mean" << std::endl;
  std::cout << "yaaaasss sis" << std::endl;
  return 0;
}