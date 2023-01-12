#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap Constructor Call" << std::endl;
    hit_points = FRAG_DEFAULT_HIT_POINT;
    energy_points = FRAG_DEFAULT_ENERGY_POINT;
    attack_damage = FRAG_DEFAULT_ATTACK_DAMAGE;
}

FragTrap::FragTrap(std::string Name)
{
    std::cout << "FragTrap Constructor Call" << std::endl;
    hit_points = FRAG_DEFAULT_HIT_POINT;
    energy_points = FRAG_DEFAULT_ENERGY_POINT;
    attack_damage = FRAG_DEFAULT_ATTACK_DAMAGE;
    this->Name = Name;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap Constructor Call" << std::endl;
    *this = other;
}

FragTrap::~FragTrap()
{
    std::cout << "[" << Name << "]"
              << "FragTrap Destructor Call" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    hit_points = other.hit_points;
    energy_points = other.energy_points;
    attack_damage = other.attack_damage;
    Name = other.Name;
    return *this;
}

void FragTrap::highFivesGuys() const
{
    std::cout << "[" << Name << "] ha ha ha~ " << std::endl;
}
