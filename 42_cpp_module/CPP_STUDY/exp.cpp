#include <iostream>

int divide(int a, int b)
{
	if (b==0)
	{
		throw std::exception();
	}
	return (a/b);
}	

int main()
{
	// try
	// {
	std::cout << divide(10, 0) << std::endl;

	// }
	// catch(std::exception &e)
	// {
	// 	std::cout << "catch error" << std::endl;
	// }
}

