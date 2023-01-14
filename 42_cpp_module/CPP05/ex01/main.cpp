#include "Bureaucrat.hpp"
#include "Form.hpp"

void end_line()
{
    std::cout << "-----------------------------" << std::endl;
}

int main()
{
    try
    {
        Bureaucrat A("A", 70);
        Bureaucrat Master("Master", 1);
        Form       form("Government's top secret", false, 1, 5);

        A.signForm(form);
        end_line();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        end_line();
    }

    try
    {
        Bureaucrat Master("Master", 1);
        Form       form("Government's top secret", false, 1, 5);

        Master.signForm(form);
        Master.signForm(form);
        end_line();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        end_line();
    }
}
