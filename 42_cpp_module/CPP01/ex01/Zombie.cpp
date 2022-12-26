#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name) : name(name)
{
}

Zombie::~Zombie()
{
}

void Zombie::set_name(std::string name)
{
    this->name = name;
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

Zombie* Zombie::zombieHorde(int N, std::string name)
{
    Zombie* zombies = new Zombie[N];

    for (int i = 0; i < N; ++i)
        zombies[i].set_name(name + std::to_string(i));
    return &zombies[0];
}
