#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern Constructor Call" << std::endl;
}

Intern::Intern(const Intern& other)
{
    std::cout << "Intern Constructor Call" << std::endl;
    *this = other;
}

Intern::~Intern()
{
    std::cout << "Intern Destructor Call" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this == &other)
        return *this;
    std::cout << "Intern Assignment Operator Call" << std::endl;
    return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    int         num;
    std::string Forms[4] = {"robotomy request", "presidential pardon", "shrubbery Creation", "null"};

    for (int i = 0; i < 4; ++i)
    {
        num = i;
        if (target == Forms[i])
            break;
    }

    switch (num)
    {
    case 0:
        return new RobotomyRequestForm(name, target);
        break;
    case 1:
        return new PresidentialPardonForm(name, target);
        break;
    case 2:
        return new ShrubberyCreationForm(name, target);
        break;
    default:
        throw Intern::InVaildForm();
    }
}

const char* Intern::InVaildForm::what() const throw()
{
    return "InVaildForm !!!";
}
