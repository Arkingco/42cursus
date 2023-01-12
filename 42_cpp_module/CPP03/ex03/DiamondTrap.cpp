#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap Constructor Call" << std::endl;
    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(std::string Name)
{
    std::cout << "DiamondTrap Constructor Call" << std::endl;
    ClapTrap::Name = Name + "_clap_name";
    this->Name = Name;
    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other)
{
    std::cout << "DiamondTrap Constructor Call" << std::endl;
    *this = other;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "[" << Name << "]"
              << "DiamondTrap Destructor Call" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    hit_points = other.hit_points;
    energy_points = other.energy_points;
    attack_damage = other.attack_damage;
    Name = other.Name;
    ClapTrap::Name = other.Name + "_clap_name";
    return *this;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I AM DIAMOND MONSTER CLASS!!!!" << std::endl;
}
