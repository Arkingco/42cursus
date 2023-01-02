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

    int N;
    std::cin >> N;

    Zombie* pointer_number_one_zombie = parent_zombie.zombieHorde(N, "Horde_Zombie_");
    for (int i = 0; i < N; i++)
        (pointer_number_one_zombie + i)->announce();
    pointer_number_one_zombie->announce();
    delete[] pointer_number_one_zombie;
}
