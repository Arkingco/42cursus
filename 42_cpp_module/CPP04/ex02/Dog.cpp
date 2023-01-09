#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Constructor Call" << std::endl;
    type = std::string("Dog");
    brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog Constructor Call" << std::endl;
    type = other.type;
    brain = new Brain(*other.brain);
}

Dog::~Dog()
{
    delete brain;
    std::cout << "["<< type << "]" << "Dog Destructor Call" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this == &other)
        return *this;
    delete brain;
    type = other.type;
    brain = new Brain(*other.brain);
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