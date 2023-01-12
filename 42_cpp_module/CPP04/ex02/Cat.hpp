#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
  protected:
    std::string type;
    Brain*      brain;

  public:
    Cat();
    Cat(const Cat& a);
    ~Cat();
    Cat& operator=(const Cat& a);

    std::string getType() const;
    void        makeSound() const;
};

#endif
