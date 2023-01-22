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
       Span a(5);

       a.addNumber(1);
       a.addNumber(2);
       a.addNumber(3);
       a.addNumber(4);
       a.addNumber(5);

       std::cout << a.longestSpan() << " " << a.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
       Span a(10000);

       for (int i=0; i<10000; ++i)
            a.addNumber(rand() % 100000);
       std::cout << a.longestSpan() << " " << a.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
