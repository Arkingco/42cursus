#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

#define FRAG_DEFAULT_HIT_POINT 100
#define FRAG_DEFAULT_ENERGY_POINT 100
#define FRAG_DEFAULT_ATTACK_DAMAGE 30

class FragTrap : virtual public ClapTrap
{
  public:
    FragTrap();
    FragTrap(std::string Name);
    FragTrap(const FragTrap& a);
    ~FragTrap();
    FragTrap& operator=(const FragTrap& a);

    void highFivesGuys() const;
};

#endif
