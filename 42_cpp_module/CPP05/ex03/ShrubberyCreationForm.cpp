#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Constructor Call" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", false, 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm Constructor Call" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target)
    : AForm(name, false, 145, 137), target(target)
{
    std::cout << "RobotomyRequestForm Constructor Call" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
    std::cout << "ShrubberyCreationForm Constructor Call" << std::endl;
    *this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor Call" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this == &other)
        return *this;
    std::cout << "ShrubberyCreationForm Assignment Operator Call" << std::endl;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    {
        is_signed_grade(executor);
        std::string   file_name = target + std::string("_shrubbery");
        std::ofstream file(file_name);
        if (!file.is_open())
            throw FileOpenError();
        std::string tree = "       _-_         \n"
                           "    /~~   ~~\\     \n"
                           " /~~         ~~\\  \n"
                           "{               }  \n"
                           " \\  _-     -_  /  \n"
                           "   ~  \\ \\/\\/  ~ \n"
                           "_- -   | | _- _    \n"
                           "  _ -  | |   -_    \n"
                           "      // \\        ";
        file << tree;
        std::cout << tree << std::endl;
    }
}
