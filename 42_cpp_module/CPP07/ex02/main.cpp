#include "Iter.hpp"

template<typename T>
void print_array(T t)
{
	std::cout << t << std::endl;
}

int main( void ) {
	
	int a[5] = {1,2,3,4,5};
	iter(a, 5, &print_array);
	std::cout << std::endl;
	
	std::string b[5] = {"a", "b", "c", "d", "e"};
	iter(b, 5, &print_array);
	std::cout << std::endl;

	double c[5] = {0.1, 0.2, 0.3, 0.4, 0.5};
	iter(c, 5, &print_array);
	std::cout << std::endl;

	return 0;
}