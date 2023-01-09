#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
  protected:
    std::string type;
  
  public:
    Animal();
    Animal(const Animal& a);
    virtual ~Animal();
    Animal& operator=(const Animal& a);

    virtual std::string getType() const;
    virtual void makeSound() const;
};

#endif
