#include "error.hpp"

int is_cin_success()
{
    if (std::cin.eof() || std::cin.fail() || std::cin.bad())
        return (0);
    return (1);
}

void print_error(std::string error_msg)
{
    std::cout << error_msg << std::endl;
}
