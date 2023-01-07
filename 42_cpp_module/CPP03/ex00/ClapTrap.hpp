#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define DEFAULT_HIT_POINT 10
#define DEFAULT_ENERGY_POINT 10
#define DEFAULT_ATTACK_DAMAGE 0

class ClapTrap
{
  private:
    std::string Name;
    int         hit_points;
    int         energy_points;
    int         attack_damage;
    bool        is_works();
    bool        is_energy_point();
    bool        is_hit_point();

  public:
    ClapTrap();
    ClapTrap(std::string Name);
    ClapTrap(const ClapTrap& a);
    ~ClapTrap();
    ClapTrap& operator=(const ClapTrap& a);

    int  get_attack_damage() const;
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void print_status() const;
};

#endif
