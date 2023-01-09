#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Constructor Call" << std::endl;
    type = std::string("Cat");
    brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat Constructor Call" << std::endl;
    type = other.type;
    brain = new Brain(*other.brain);
}

Cat::~Cat()
{
    delete brain;
    std::cout << "["<< type << "]" << "Cat Destructor Call" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this == &other)
        return *this;
    delete brain;
    type = other.type;
    brain = new Brain(*other.brain);
    std::cout << "Cat Assignment Operator Call" << std::endl;
    return *this;
}

std::string Cat::getType() const
{
    return type;
}

void Cat::makeSound() const
{
    std::cout << "Meow~" << std::endl;
}
