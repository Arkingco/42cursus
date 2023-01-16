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
    srand(time(NULL));
    try
    {
        Bureaucrat Master("Master", 1);
        Bureaucrat A("Master", 150);

        AForm* Shrubbery = new ShrubberyCreationForm("Shrubbery");
        AForm* Robotomy = new RobotomyRequestForm("Robotomy");
        AForm* Presidential = new PresidentialPardonForm("Presidential");
        end_line();

        Master.executeForm(*Shrubbery);
        end_line();
        Master.signForm(*Shrubbery);
        Master.executeForm(*Shrubbery);
        end_line();
        Master.signForm(*Robotomy);
        Master.executeForm(*Robotomy);
        end_line();
        Master.signForm(*Presidential);
        Master.executeForm(*Presidential);
        end_line();

        A.executeForm(*Shrubbery);
        delete Shrubbery;
        delete Robotomy;
        delete Presidential;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        end_line();
    }
}
