#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void end_line()
{
    std::cout << "-----------------------------" << std::endl;
}

int main()
{
    try
    {
        Bureaucrat Master("Master", 1);
        AForm*     Shrubbery = new ShrubberyCreationForm("Shrubbery");
        AForm*     Robotomy = new RobotomyRequestForm("Robotomy");
        AForm*     Presidential = new PresidentialPardonForm("Presidential");
        end_line();

        Master.executeForm(*Shrubbery);
        Master.signForm(*Shrubbery);
        Master.executeForm(*Shrubbery);
        end_line();
        Master.signForm(*Robotomy);
        Master.executeForm(*Robotomy);
        end_line();
        Master.signForm(*Presidential);
        Master.executeForm(*Presidential);
        end_line();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        end_line();
    }
}
