#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
}

Zombie::~Zombie()
{
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie* Zombie::newZombie(std::string name)
{
    return (new Zombie(name));
}
void Zombie::randomChump(std::string name)
{
    Zombie* new_zombie = newZombie(name);
    new_zombie->announce();
    delete new_zombie;
}
