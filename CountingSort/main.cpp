#include "count.hpp"

int main(void){
	std::vector<int> vec{2,1,2,5,8,2,1,9, 0};
	display(vec);
	counting_sort(vec);
	display(vec);
	std::cout << "soir, au revoir" << std::endl;
	return 0;
}