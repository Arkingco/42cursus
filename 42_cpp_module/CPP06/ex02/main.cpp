#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate()
{

    int num;
    num = rand() % 3;
    if (num == 0)
        return new A();
    else if (num == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{ 
    std::cout << "[in * identify]Base class -> ";
    if (dynamic_cast<A *>(p))
        std::cout << "A!!" << std::endl;
    else if(dynamic_cast<B *>(p))
        std::cout << "B!!" << std::endl;
    else if(dynamic_cast<C *>(p))
        std::cout << "C!!" << std::endl;
}

void identify(Base& p)
{
    A a;
    B b;
    C c;

    try
    {
        a = dynamic_cast<A&>(p);
        std::cout << "[in & identify]Base class -> A!!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        b = dynamic_cast<B&>(p);
        std::cout << "[in & identify]Base class -> B!!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        c = dynamic_cast<C&>(p);
        std::cout << "[in & identify]Base class -> C!!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    std::srand(time(NULL));

    Base *p;

    p = generate();
    identify(p);
    identify(*p);
}