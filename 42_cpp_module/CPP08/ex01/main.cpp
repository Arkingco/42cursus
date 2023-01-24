#include "Span.hpp"


int main()
{
    srand(time(NULL));

    try
    {
        Span a(1);

        a.addNumber(1);
        a.addNumber(2);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    try
    {
        Span a(1);

        std::cout << "longesSpan : " << a.longestSpan() << "    shortestSpan : " << a.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Span a(1);

        a.addNumber(1);
        std::cout << "longesSpan : " << a.longestSpan() << "    shortestSpan : " << a.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Span a(5);

        a.addNumber(1);
        a.addNumber(2);
        a.addNumber(3);
        a.addNumber(4);
        a.addNumber(5);

        std::cout << "longesSpan : " << a.longestSpan() << "    shortestSpan : " << a.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Span a(10000);

        a.addManyNumber();
        std::cout << "longesSpan : " << a.longestSpan() << "    shortestSpan : " << a.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
