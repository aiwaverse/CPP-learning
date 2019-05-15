#include "hash.hpp"

int main(void){
	using std::cin;
	using std::cout; 
	using std::endl;
	Hash_Table table {};
	cout << table << endl;
	table.insert(9);
	table.insert(2);
	table.insert(24);
	cout << table << endl;

	cout << "trying to be stronger for you" << endl;
	return 0;
}