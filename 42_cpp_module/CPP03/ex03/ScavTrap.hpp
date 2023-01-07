#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

#define SCAV_DEFAULT_HIT_POINT 100
#define SCAV_DEFAULT_ENERGY_POINT 50
#define SCAV_DEFAULT_ATTACK_DAMAGE 20

class ScavTrap : virtual public ClapTrap
{
  public:
    ScavTrap();
    ScavTrap(std::string Name);
    ScavTrap(const ScavTrap& a);
    ~ScavTrap();
    ScavTrap& operator=(const ScavTrap& a);

    void attack(const std::string& target);
    void guardGate() const;
};

#endif
