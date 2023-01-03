#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
    ClapTrap Kim("Kim");
    ClapTrap Lee("Lee");
    ClapTrap Park("Park");
    ScavTrap Scav_Kim("Scav_Kim");
    ScavTrap Scav_Lee("Scav_Lee");
    ScavTrap Scav_Park("Scav_Park");

    Kim.print_status();
    Lee.print_status();
    Park.print_status();
    Scav_Kim.print_status();
    Scav_Lee.print_status();
    Scav_Park.print_status();

    Scav_Kim.guardGate();
    Scav_Lee.attack("Scav_Kim");
    Scav_Kim.takeDamage(Scav_Lee.get_attack_damage());
    Scav_Kim.guardGate();
    Scav_Lee.attack("Scav_Kim");
    Scav_Kim.takeDamage(Scav_Lee.get_attack_damage());
    Scav_Kim.guardGate();
    Scav_Lee.attack("Scav_Kim");
    Scav_Kim.takeDamage(Scav_Lee.get_attack_damage());
    Scav_Kim.guardGate();
    Scav_Lee.attack("Scav_Kim");
    Scav_Kim.takeDamage(Scav_Lee.get_attack_damage());
    Scav_Kim.guardGate();
}
