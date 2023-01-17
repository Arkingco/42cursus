#include "Bureaucrat.hpp"

void end_line()
{
    std::cout << "-----------------------------" << std::endl;
}

int main()
{

    try
    {
        Bureaucrat A("A", 148);
        std::cout << A << std::endl;

        A.decrement();
        A.decrement();
        A.decrement();
        end_line();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        end_line();
    }

    try
    {
        Bureaucrat B("B", 3);
        std::cout << B << std::endl;

        B.increment();
        B.increment();
        B.increment();
        end_line();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        end_line();
    }

    try
    {
        Bureaucrat C("C", 0);
        end_line();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        end_line();
    }

    try
    {
        Bureaucrat D("D", 151);
        end_line();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        end_line();
    }
}
