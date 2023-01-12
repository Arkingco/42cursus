#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
  private:
    std::string type;

  public:
    WrongCat();
    WrongCat(const WrongCat& a);
    ~WrongCat();
    WrongCat& operator=(const WrongCat& a);

    std::string getType() const;
    void        makeSound() const;
};

#endif