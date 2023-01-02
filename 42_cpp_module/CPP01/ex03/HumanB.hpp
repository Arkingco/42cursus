#ifndef HUMAN_B
#define HUMAN_B

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
  private:
    Weapon*     weapon;
    std::string name;

  public:
    HumanB(std::string name);
    void setWeapon(Weapon& weapon);
    void attack();
};

#endif
