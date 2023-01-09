#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Constructor Call" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal Constructor Call" << std::endl;
    *this = other;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "["<< type << "---]" << "WrongAnimal Destructor Call" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this == &other)
        return *this;
    type = other.type;
    std::cout << "WrongAnimal Assignment Operator Call" << std::endl;
    return *this;
}

std::string WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal Sound !! " << std::endl;
}