#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

#define SCAV_DEFAULT_HIT_POINT 100
#define SCAV_DEFAULT_ENERGY_POINT 100
#define SCAV_DEFAULT_ATTACK_DAMAGE 30

class FragTrap : public ClapTrap
{
  private:
    bool is_works();

  public:
    FragTrap();
    FragTrap(std::string Name);
    FragTrap(const FragTrap& a);
    ~FragTrap();
    FragTrap& operator=(const FragTrap& a);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    int  get_attack_damage() const;
    void print_status() const;
    void highFivesGuys() const;
};

#endif
