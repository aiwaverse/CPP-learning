//an even more different shellsort code, this time full of variants, with powers of 2 and the ciura list + extra numbers
//use calculate time to get execution time
//the shellsort_basic and shellsort_even_more_basic run on powers of 2, first one with insert/erase, second with the classic method
//same for shellsort_ciura and shellsort_ciura_basic
//the "classic" methods are extremely more efficient

#include "shellsort.hpp"
using namespace std::chrono;
int main(void)
{
  std::vector<int> vec {32,7,3,15,13,4,21,6};
  shellsort_even_more_basic(vec);
  return 0;
}