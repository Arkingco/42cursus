#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Constructor Call" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", false, 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm Constructor Call" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target)
    : AForm(name, false, 25, 5), target(target)
{
    std::cout << "RobotomyRequestForm Constructor Call" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{
    std::cout << "PresidentialPardonForm Constructor Call" << std::endl;
    *this = other;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Destructor Call" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this == &other)
        return *this;
    std::cout << "PresidentialPardonForm Assignment Operator Call" << std::endl;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    is_signed_grade(executor);
    std::cout << "Informs that" << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
