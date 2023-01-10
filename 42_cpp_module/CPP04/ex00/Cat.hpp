#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

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
    void        makeSound() const;
};

#endif
