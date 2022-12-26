#ifndef HUMAN_A
#define HUMAN_A

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
  private:
    std::string name;
    Weapon&     weapon;

  public:
    HumanA(std::string name, Weapon& weapon);
    void attack();
};

#endif
