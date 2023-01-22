#include "Easyfind.hpp"
#include <vector>

int main( void ) {

	
	std::vector<int> a;
	std::vector<std::string> b;
	std::vector<char> c;

	a.push_back(10);
	a.push_back(11);
	a.push_back(124);
	a.push_back(51);
	a.push_back(1);

	b.push_back("hi");
	b.push_back("my");
	b.push_back("name");
	b.push_back("is");
	b.push_back("kipark!");

	c.push_back('a');
	c.push_back('b');
	c.push_back('c');
	c.push_back('d');
	c.push_back('e');

	try
	{
		std::cout << *(easyfind(a, 124)) << std::endl;
		std::cout << *(easyfind(a, 5555)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::cout << *(easyfind(b, 12)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	// try
	// {
	// 	std::cout << *(easyfind(c, 86)) << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	return 0;
}