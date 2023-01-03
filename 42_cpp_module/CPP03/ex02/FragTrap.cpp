#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap Constructor Call" << std::endl;
    hit_points = SCAV_DEFAULT_HIT_POINT;
    energy_points = SCAV_DEFAULT_ENERGY_POINT;
    attack_damage = SCAV_DEFAULT_ATTACK_DAMAGE;
}

FragTrap::FragTrap(std::string Name)
{
    std::cout << "FragTrap Constructor Call" << std::endl;
    hit_points = SCAV_DEFAULT_HIT_POINT;
    energy_points = SCAV_DEFAULT_ENERGY_POINT;
    attack_damage = SCAV_DEFAULT_ATTACK_DAMAGE;
    this->Name = Name;
}

FragTrap::FragTrap(const FragTrap& other)
{
    std::cout << "FragTrap Constructor Call" << std::endl;
    *this = other;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor Call" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    hit_points = other.hit_points;
    energy_points = other.energy_points;
    attack_damage = other.attack_damage;
    Name = other.Name;
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (is_works() == 0)
        return;
    std::cout << "FragTrap " << Name << " attacks " << target << ", causing " << attack_damage << " points of damage!"
              << std::endl;
    energy_points--;
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (is_works() == 0)
        return;
    std::cout << Name << " is Take damage ... " << std::endl;
    std::cout << "damage amount: " << amount << std::endl;
    hit_points -= amount;
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (is_works() == 0)
        return;
    std::cout << Name << " be Repaired ! ! ! " << std::endl;
    std::cout << "Repaired amount : " << amount << std::endl;
    energy_points--;
    hit_points += amount;
}

int FragTrap::get_attack_damage() const
{
    return (attack_damage);
}

void FragTrap::print_status() const
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "NA : " << Name << std::endl;
    std::cout << "HP : " << hit_points << std::endl;
    std::cout << "AD : " << attack_damage << std::endl;
    std::cout << "EP : " << energy_points << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << std::endl;
}

void FragTrap::highFivesGuys() const
{
    std::cout << "[" << Name << "] ha ha ha~ " << std::endl;
}

bool FragTrap::is_works()
{
    if (hit_points <= 0 || energy_points <= 0)
    {
        std::cout << "[" << Name << "] "
                  << "I don't have power... (_ _)" << std::endl;
        return (0);
    }
    return (1);
}
