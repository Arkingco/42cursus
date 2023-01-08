#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

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
