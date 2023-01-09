#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Constructor Call" << std::endl;
    type = std::string("Dog");
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog Constructor Call" << std::endl;
    *this = other;
}

Dog::~Dog()
{
    std::cout << "["<< type << "]" << "Dog Destructor Call" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this == &other)
        return *this;
    type = other.type;
    std::cout << "Dog Assignment Operator Call" << std::endl;
    return *this;
}

std::string Dog::getType() const
{
    return type;
}

void Dog::makeSound() const
{
    std::cout << "Bark~ " << std::endl;
}