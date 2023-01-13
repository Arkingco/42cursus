#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

void end_line()
{
    std::cout << "-----------------------------" << std::endl;
}

int main()
{
    try
    {
        Bureaucrat            Master("Master", 1);
        ShrubberyCreationForm Tree("JO");
        end_line();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        end_line();
    }
}
