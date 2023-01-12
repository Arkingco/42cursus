#include "Bureaucrat.hpp"
#include "Form.hpp"

void end_line()
{
	std::cout << "-----------------------------" << std::endl;
}

int main()
{
	try 
	{
		Bureaucrat A("A", 70);
		Form form("Government's top secret", false, 1, 5);

		end_line();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		end_line();
	}
}