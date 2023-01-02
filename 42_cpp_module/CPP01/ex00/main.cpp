#include "Zombie.hpp"

int main()
{
    Zombie  parent_zombie("parent_zombie");
    Zombie  foo = Zombie(std::string("foo"));
    Zombie* pointer_zombie = parent_zombie.newZombie("pointer_zombie");
    parent_zombie.announce();
    foo.announce();
    pointer_zombie->announce();
    parent_zombie.randomChump("child_zombie");

    delete pointer_zombie;
}
