#include "Bureaucrat.hpp"

void end_line()
{
	std::cout << "-----------------------------" << std::endl;
}

int main()
{

	try 
	{
		Bureaucrat A("A", 70);
		std::cout << A << std::endl;

		A.increment(10);
		A.decrement(20);
		A.decrement(70);
		A.decrement(1);
		end_line();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		end_line();
	}

	try 
	{
		Bureaucrat B("B", 70);
		std::cout << B << std::endl;

		B.increment(60);
		B.increment(9);
		B.increment(1);
		end_line();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		end_line();
	}

	try 
	{
		Bureaucrat C("C", 0);
		end_line();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		end_line();
	}

	try 
	{
		Bureaucrat D("D", 151);
		end_line();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		end_line();
	}
	
}