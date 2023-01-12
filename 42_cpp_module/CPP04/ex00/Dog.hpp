#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
  private:
    std::string type;

  public:
    Dog();
    Dog(const Dog& a);
    ~Dog();
    Dog& operator=(const Dog& a);

    std::string getType() const;
    void        makeSound() const;
};

#endif
