#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap Kim("Kim");
    std::cout << "---------------------------------\n\n" << std::endl;
    FragTrap Frag_Kim("Frag_Kim");
    std::cout << "---------------------------------\n\n" << std::endl;
    ScavTrap Scav_kim("Scav_kim");
    std::cout << "---------------------------------\n\n" << std::endl;
    DiamondTrap Dia_kim("Dia_kim");
    std::cout << "---------------------------------\n\n" << std::endl;

    Kim.print_status();
    Frag_Kim.print_status();
    Scav_kim.print_status();
    Dia_kim.print_status();
}
