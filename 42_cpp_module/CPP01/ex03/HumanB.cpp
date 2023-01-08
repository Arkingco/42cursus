#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
    weapon = NULL;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
    if (weapon == NULL)
    {
        std::cout << "I don't have weapon.. (@__@)" << std::endl;
        return ;
    }
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
