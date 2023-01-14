#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Constructor Call" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", false, 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm Constructor Call" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
    std::cout << "RobotomyRequestForm Constructor Call" << std::endl;
    *this = other;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor Call" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this == &other)
        return *this;
    std::cout << "RobotomyRequestForm Assignment Operator Call" << std::endl;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    is_signed_grade(executor);
    std::cout << "* DRILLING NOISES *" << std::endl << target;
    if (rand() % 2)
        std::cout << " has been successfully robotimized!" << std::endl;
    else
        std::cout << " had some problems and its robotomy failed!" << std::endl;
}
