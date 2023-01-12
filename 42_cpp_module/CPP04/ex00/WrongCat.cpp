#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat Constructor Call" << std::endl;
    type = std::string("WrongCat");
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat Constructor Call" << std::endl;
    *this = other;
}

WrongCat::~WrongCat()
{
    std::cout << "[" << type << "]"
              << "WrongCat Destructor Call" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this == &other)
        return *this;
    type = other.type;
    std::cout << "WrongCat Assignment Operator Call" << std::endl;
    return *this;
}

std::string WrongCat::getType() const
{
    return type;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow~" << std::endl;
}
