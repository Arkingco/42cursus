#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Constructor Call" << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal Constructor Call" << std::endl;
    *this = other;
}

Animal::~Animal()
{
    std::cout << "[" << type << "---]"
              << "Animal Destructor Call" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this == &other)
        return *this;
    type = other.type;
    std::cout << "Animal Assignment Operator Call" << std::endl;
    return *this;
}