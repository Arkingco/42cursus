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

    try
    {
        std::vector<int> a(100);
        Span b(a.size());
        for (int i=0; i<100; ++i)
            a[i] = i + 1;

        b.addManyNumber< std::vector<int> >(a.begin(), a.end());
        std::cout << "longesSpan : " << b.longestSpan() << "    shortestSpan : " << b.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
