#include "Array.hpp"

int main( void ) {
	
	int n = 5;
	try
	{
		Array<int> a(n);

		for (int i=0; i<n; ++i)
			a[i] = i + 1;
		std::cout << a << std::endl;
		std::cout << "size : " << a.size() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------- " << std::endl;

	try
	{
		Array<std::string> b(n);

		std::cout << b[n + 1] << std::endl;
		std::cout << "size : " << b.size() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------- " << std::endl;

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
	std::cout << "-------------------------------------- " << std::endl;

	try
	{
		Array<int> c(n);
		for (int i=0; i<n; ++i)
			c[i] = i + 1;

		Array<int> d(c);
		for (int i=0; i<n; ++i)
			d[i] = d[i] + 5;
		
		std::cout << c << d << std::endl;
		std::cout << "size : " << c.size() << std::endl;
		std::cout << "size : " << d.size() << std::endl;
	} 
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------- " << std::endl;

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
		std::cout << "size : " << e.size() << std::endl;
		std::cout << "size : " << f.size() << std::endl;
	} 
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------- " << std::endl;


	try
	{
		Array<int> g;
	} 
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}