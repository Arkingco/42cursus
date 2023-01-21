#include "Array.hpp"
#include <stdlib.h>

int main( void ) {
	
	int n = 5;
	try
	{
		Array<int> a(n);

		for (int i=0; i<n; ++i)
			a[i] = i + 1;
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Array<std::string> b(n);

		std::cout << b[n + 1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Array<std::string> b(n);

		for (int i=0; i<n; ++i)
			b[i] = "string!";
		std::cout << b << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Array<int> c(n);
		for (int i=0; i<n; ++i)
			c[i] = i + 1;

		Array<int> d(c);
		for (int i=0; i<n; ++i)
			d[i] = d[i] + 5;
		
		std::cout << c << d << std::endl;
	} 
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Array<int> f;
		Array<int> e(n);
		for (int i=0; i<n; ++i)
			e[i] = i + 1;

		f = e;
	
		for (int i=0; i<n; ++i)
			f[i] = f[i] + 10;
		std::cout << f;
	} 
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}