#include<iostream>

int is_cin_succes()
{
    if (std::cin.eof() || std::cin.fail() || std::cin.bad())
        return (0);
    return (1);
}
