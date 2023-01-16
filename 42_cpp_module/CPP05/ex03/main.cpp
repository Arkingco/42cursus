#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
        Intern     intern;

        AForm* form_a = intern.makeForm("Robot", "robotomy request");
        Master.signForm(*form_a);
        Master.executeForm(*form_a);
        delete form_a;

        end_line();
        AForm* form_b = intern.makeForm("Pre", "presidential pardon");
        Master.signForm(*form_b);
        Master.executeForm(*form_b);
        delete form_b;

        end_line();
        AForm* form_c = intern.makeForm("Tree", "shrubbery Creation");
        Master.signForm(*form_c);
        Master.executeForm(*form_c);
        delete form_c;

        end_line();
        AForm* form_d = intern.makeForm("Wrong", "asdfsda");
        Master.signForm(*form_d);
        Master.executeForm(*form_d);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        end_line();
    }
}
