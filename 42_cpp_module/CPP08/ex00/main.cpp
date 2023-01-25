#include "easyfind.hpp"

template<typename T>
void printContainer(typename T::iterator con_begin, typename T::iterator con_end)
{
	for (typename T::iterator iter = con_begin; iter != con_end; iter++)
		std::cout << *iter << std::endl;
}

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
		std::cout << "-------------- vector ----------------" << std::endl;
		printContainer<std::vector<int> >(easyfind(a, 124), a.end());
		printContainer<std::vector<int> >(easyfind(a, 5555), a.end());
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "---------------- list ----------------" << std::endl;
		printContainer<std::list<int> >(easyfind(b, 12), b.end());
		printContainer<std::list<int> >(easyfind(b, 1000), b.end());
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "-------------- deque ----------------" << std::endl;
		printContainer<std::deque<int> >(easyfind(c, 5), c.end());
		printContainer<std::deque<int> >(easyfind(c, 100), c.end());
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}