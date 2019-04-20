#include "heap.hpp"

int main(void){
	std::vector<int> vec {3, 7, 1, 0, 6, 8, 9, 4, 2, 5};
	display(vec);
	heapsort(vec);
	display(vec);
	std::cout << "9/6 gogobebe" << std::endl;
	return 0;
}