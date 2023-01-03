#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap Constructor Call" << std::endl;
    hit_points = SCAV_DEFAULT_HIT_POINT;
    energy_points = SCAV_DEFAULT_ENERGY_POINT;
    attack_damage = SCAV_DEFAULT_ATTACK_DAMAGE;
}

ScavTrap::ScavTrap(std::string Name)
{
    std::cout << "ScavTrap Constructor Call" << std::endl;
    hit_points = SCAV_DEFAULT_HIT_POINT;
    energy_points = SCAV_DEFAULT_ENERGY_POINT;
    attack_damage = SCAV_DEFAULT_ATTACK_DAMAGE;
    this->Name = Name;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    std::cout << "ScavTrap Constructor Call" << std::endl;
    *this = other;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor Call" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    hit_points = other.hit_points;
    energy_points = other.energy_points;
    attack_damage = other.attack_damage;
    Name = other.Name;
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (is_works() == 0)
        return;
    std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << attack_damage << " points of damage!"
              << std::endl;
    energy_points--;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (is_works() == 0)
        return;
    std::cout << Name << " is Take damage ... " << std::endl;
    std::cout << "damage amount: " << amount << std::endl;
    hit_points -= amount;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (is_works() == 0)
        return;
    std::cout << Name << " be Repaired ! ! ! " << std::endl;
    std::cout << "Repaired amount : " << amount << std::endl;
    energy_points--;
    hit_points += amount;
}

int ScavTrap::get_attack_damage() const
{
    return (attack_damage);
}

void ScavTrap::print_status() const
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "NA : " << Name << std::endl;
    std::cout << "HP : " << hit_points << std::endl;
    std::cout << "AD : " << attack_damage << std::endl;
    std::cout << "EP : " << energy_points << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << std::endl;
}

void ScavTrap::guardGate() const
{
    std::cout << " I'm in keeper mode my 'STATUS' is " << std::endl;
    print_status();
    if (hit_points >= 70)
        std::cout << "I'm very good right now. I can do anything!" << std::endl;
    else if (hit_points >= 40)
        std::cout << "I'm fine.. maybe a little hard..?" << std::endl;
    else
        std::cout << "I'm tired..,,,,,, I want go home!!!!" << std::endl;
    std::cout << std::endl;
}

bool ScavTrap::is_works()
{
    if (hit_points <= 0 || energy_points <= 0)
    {
        std::cout << "[" << Name << "] "
                  << "I don't have power... (_ _)" << std::endl;
        return (0);
    }
    return (1);
}
