#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat Constructor Call" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    std::cout << "Bureaucrat Constructor Call" << std::endl;
    *this = other;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "["<< type << "---]" << "Bureaucrat Destructor Call" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this == &other)
        return *this;
    type = other.type;
    std::cout << "Bureaucrat Assignment Operator Call" << std::endl;
    return *this;
}