#include "radix.hpp"

int main(void){
	std::vector<int> vec {170, 45, 75, 90, 802, 24, 2, 66};
	display(vec);
	radix_sort(vec);
	display(vec);
	std::cout << "dulmanui canvas gadeuk chaewo naga" << std::endl;
	return 0;
}