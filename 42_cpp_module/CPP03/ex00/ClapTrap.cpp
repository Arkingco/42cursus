#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Constructor Call" << std::endl;
    hit_points = DEFAULT_HIT_POINT;
    energy_points = DEAFULT_ENERGY_POINT;
    attack_damage = DEFAULT_ATTACK_DAMAGE;
}

ClapTrap::ClapTrap(std::string Name)
{
    std::cout << "ClapTrap Constructor Call" << std::endl;
    hit_points = DEFAULT_HIT_POINT;
    energy_points = DEAFULT_ENERGY_POINT;
    attack_damage = DEFAULT_ATTACK_DAMAGE;
    this->Name = Name;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap Constructor Call" << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor Call" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    hit_points = other.hit_points;
    energy_points = other.energy_points;
    attack_damage = other.attack_damage;
    Name = other.Name;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (is_works() == 0)
        return;
    std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << attack_damage << " points of damage!"
              << std::endl;
    energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (is_works() == 0)
        return;
    std::cout << Name << " is Take damage ... " << std::endl;
    std::cout << "damage amount: " << amount << std::endl;
    hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (is_works() == 0)
        return;
    std::cout << Name << " be Repaired ! ! ! " << std::endl;
    std::cout << "Repaired amount : " << amount << std::endl;
    energy_points--;
    hit_points += amount;
}

void ClapTrap::print_status() const
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "NA : " << Name << std::endl;
    std::cout << "HP : " << hit_points << std::endl;
    std::cout << "AD : " << attack_damage << std::endl;
    std::cout << "EP : " << energy_points << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << std::endl;
}

int ClapTrap::get_attack_damage() const
{
    return (attack_damage);
}

bool ClapTrap::is_works()
{
    if (hit_points <= 0 || energy_points <= 0)
    {
        std::cout << "[" << Name << "] "
                  << "I don't have power... (_ _)" << std::endl;
        return (0);
    }
    return (1);
}
