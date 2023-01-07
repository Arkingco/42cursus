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

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap Constructor Call" << std::endl;
    *this = other;
}

ScavTrap::~ScavTrap()
{
    std::cout << "["<< Name << "]" << "ScavTrap Destructor Call" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    hit_points = other.hit_points;
    energy_points = other.energy_points;
    attack_damage = other.attack_damage;
    Name = other.Name;
    return *this;
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

void ScavTrap::attack(const std::string& target)
{
     if (is_works() == 0)
        return;
    std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << attack_damage << " points of damage!"
              << std::endl;
    energy_points--;
}
