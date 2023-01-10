#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    DiamondTrap Dia_kim("Dia_kim");
    std::cout << "---------------------------------\n\n" << std::endl;

    Dia_kim.whoAmI();
    Dia_kim.guardGate();
    Dia_kim.highFivesGuys();
    std::cout << std::endl;
    ScavTrap Scav_park("Scav_park");
    Dia_kim.attack("Scav_park");
    Scav_park.takeDamage(Dia_kim.get_attack_damage());
    std::cout << std::endl;
    Scav_park.print_status();
}
