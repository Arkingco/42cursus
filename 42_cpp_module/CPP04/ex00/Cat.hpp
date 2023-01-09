#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
  private:
    std::string type;
  
  public:
    Cat();
    Cat(const Cat& a);
    ~Cat();
    Cat& operator=(const Cat& a);

    std::string getType() const;
    void makeSound() const;
};

#endif
