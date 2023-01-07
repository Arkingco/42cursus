#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap
{
  private:
    std::string name;
  
  public:
    DiamondTrap();
    DiamondTrap(std::string Name);
    DiamondTrap(const DiamondTrap& a);
    ~DiamondTrap();
    DiamondTrap& operator=(const DiamondTrap& a);

    void attack(const std::string& target);
    void whoAmI();
};

#endif
