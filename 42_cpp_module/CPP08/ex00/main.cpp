#include "Easyfind.hpp"


int main( void ) {

	
	std::vector<int> a;
	std::list<int> b;
	std::deque<int> c;

	a.push_back(10);
	a.push_back(11);
	a.push_back(124);
	a.push_back(51);
	a.push_back(1);

	b.push_back(12);
	b.push_back(15);
	b.push_back(17);
	b.push_back(87);
	b.push_back(123);

	c.push_back(1);
	c.push_back(2);
	c.push_back(3);
	c.push_back(4);
	c.push_back(5);

	try
	{
		std::cout << "vector ----------------" << std::endl;
		std::cout << *(easyfind(a, 124)) << std::endl;
		std::cout << *(easyfind(a, 5555)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "list ----------------" << std::endl;
		std::cout << *(easyfind(b, 12)) << std::endl;
		std::cout << *(easyfind(b, 1000)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "deque ----------------" << std::endl;
		std::cout << *(easyfind(c, 5)) << std::endl;
		std::cout << *(easyfind(c, 100)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}