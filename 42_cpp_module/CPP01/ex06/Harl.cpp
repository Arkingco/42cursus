#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;
    std::cout << std::endl;
}

void Harl::info()
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money" << std::endl;
    std::cout << "You didn’t put enough bacon in my burger !If " << std::endl;
    std::cout << "you did, I wouldnt be asking for more!" << std::endl;
    std::cout << std::endl;
}

void Harl::warning()
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
}

void Harl::error()
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

void Harl::tired()
{
    std::cout << " [ Probably complaining about insignificant problems ] " << std::endl;
    std::cout << std::endl;
}

void Harl::filter(std::string level)
{
    int         filter_level;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    filter_level = INT_MAX;
    for (int i = 0; i < 4; ++i)
        if (levels[i].compare(level) == 0)
            filter_level = i;

    switch (filter_level)
    {
    case 0:
        debug();
    case 1:
        info();
    case 2:
        warning();
    case 3:
        error();
        break;
    default:
        tired();
    }
}
