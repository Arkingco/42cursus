#include "MutantStack.hpp"

MutantStack::MutantStack()
{
    std::cout << "MutantStack Constructor Call" << std::endl;
}

MutantStack::MutantStack(unsigned int N) : N(N)
{
    std::cout << "MutantStack Constructor Call" << std::endl;
}

MutantStack::MutantStack(const MutantStack& other)
{
    std::cout << "MutantStack copy Constructor Call" << std::endl;
    *this = other;
}

MutantStack::~MutantStack()
{
    std::cout << "MutantStack Destructor Call" << std::endl;
}

MutantStack& MutantStack::operator=(const MutantStack& other)
{
    if (this == &other)
        return *this;
    std::cout << "MutantStack Assignment Operator Call" << std::endl;
    return *this;
}

const char * TooManyElement::what() const throw(){
    return "TooManyElement !!";
}
