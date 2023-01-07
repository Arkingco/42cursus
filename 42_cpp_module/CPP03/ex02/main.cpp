#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap Kim("Kim");
    ClapTrap Lee("Lee");
    ClapTrap Park("Park");
    FragTrap Frag_Kim("Frag_Kim");
    FragTrap Frag_Lee("Frag_Lee");
    FragTrap Frag_Park("Frag_Park");

    Kim.print_status();
    Lee.print_status();
    Park.print_status();
    Frag_Kim.print_status();
    Frag_Lee.print_status();
    Frag_Park.print_status();

    Frag_Kim.highFivesGuys();
    Frag_Lee.highFivesGuys();
    Frag_Park.highFivesGuys();
}
