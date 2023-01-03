#include "ClapTrap.hpp"

int main()
{
    ClapTrap Kim("Kim");
    ClapTrap Lee("Lee");
    ClapTrap Park("Park");

    Kim.print_status();
    Lee.print_status();
    Park.print_status();

    Kim.attack("Park");
    Park.takeDamage(Kim.get_attack_damage());
    Park.print_status();

    Park.takeDamage(15);
    Park.print_status();

    Park.attack("Kim");
    Park.print_status();
    Kim.print_status();
}
