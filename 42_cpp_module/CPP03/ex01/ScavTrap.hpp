#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

#define SCAV_DEFAULT_HIT_POINT 100
#define SCAV_DEFAULT_ENERGY_POINT 50
#define SCAV_DEFAULT_ATTACK_DAMAGE 20

class ScavTrap : public ClapTrap
{
  private:
    bool is_works();

  public:
    ScavTrap();
    ScavTrap(std::string Name);
    ScavTrap(const ScavTrap& a);
    ~ScavTrap();
    ScavTrap& operator=(const ScavTrap& a);

    int  get_attack_damage() const;
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void print_status() const;
    void guardGate() const;
};

#endif
